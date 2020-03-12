//
//  CalculatorBrain.swift
//  Calculator
//
//  Created by NAYOHAN on 2020/03/06.
//  Copyright © 2020 NAYOHAN. All rights reserved.
//

import Foundation

class  CalculatorBrain {
    private var accumulator = 0.0 //Double
    private var internalProgram = [AnyObject]()
    
    func setOperand(operand: Double){
        accumulator = operand
        internalProgram.append(operand as NSNumber)
    }
    private var operations: Dictionary<String,Operation> = [
        "𝝿" : Operation.Constant(Double.pi), // M_PI,
        "℮" : Operation.Constant(M_E), // M_E,
        "√" : Operation.UnaryOperation(sqrt), //sqrt,
        "cos" : Operation.UnaryOperation(cos), //cos
        "×" : Operation.BinaryOperation({$0 * $1}),
        "÷" : Operation.BinaryOperation({$0 / $1}),
        "-" : Operation.BinaryOperation({$0 - $1}),
        "+" : Operation.BinaryOperation({$0 + $1}),
        "=" : Operation.Equals
    ]
    private enum Operation {
        case Constant(Double)
        case UnaryOperation((Double) -> Double)
        case BinaryOperation((Double, Double) -> Double)
        case Equals
    }
    private var pending: PendingBinaryOperationInfo?
    
    private struct PendingBinaryOperationInfo {
        var binaryFunction: (Double, Double) -> Double
        var firstOperand: Double
    }
    func performOperation(symbol: String) {
        internalProgram.append(symbol as NSString)
        if let operation = operations[symbol]{
            switch operation{
            case .Constant(let value): accumulator = value
            case .UnaryOperation(let foo): accumulator = foo(accumulator)
            case .BinaryOperation(let function):  pending = PendingBinaryOperationInfo(binaryFunction: function, firstOperand: accumulator)
            case .Equals:
                executePedingBinaryOperation()
            }
        }
    }
    private func executePedingBinaryOperation(){
        if pending != nil {
            accumulator = pending!.binaryFunction(pending!.firstOperand, accumulator)
            pending = nil
        }
    }
    typealias PropertyList = [AnyObject]
    var program: PropertyList {
        get {
            return internalProgram
        }
        set {
            clear()
            if let arrayofOps = newValue as? [AnyObject] {
                for op in arrayofOps {
                    if let operation = op as? Double{
                        setOperand(operand: operation)
                    }
                    else if let operation = op as? String{
                        performOperation(symbol: operation)
                    }
                }
            }
        }
    }
    func clear(){
        accumulator = 0.0
        pending = nil
        internalProgram.removeAll()
    }
    var result : Double{
        get {
            return accumulator
        }
    }
}
