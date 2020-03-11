//
//  ViewController.swift
//  Calculator
//
//  Created by NAYOHAN on 2020/03/06.
//  Copyright © 2020 NAYOHAN. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    //outlet -> create property
    //! -> unwrapping
    //옵셔널은 not set으로 자동 초기화됨 //강제적 추출 옵셔널
    @IBOutlet private weak var display: UILabel! //시작하자마자 버튼이 연결되어 set됨
    //false는 swift가 자동으로 타입을 추론할수 있음
    private var userIsInTheMiddleOfTyping: Bool = false
    
    
    //UIButton function
    @IBAction private func touchDigit(sender: UIButton){
        let digit = sender.currentTitle!
        
        //처음시작시 0을 없애줌 그다음부터는 덧대어 숫자출력
        if userIsInTheMiddleOfTyping {
            let textCurrentlyInDisplay = display.text!
                  display.text = textCurrentlyInDisplay + digit
        }
        else {
            display.text = digit
        }
        userIsInTheMiddleOfTyping = true
    }
    
    //자동으로 변수 자료형을 바꿔주는 Property
    private var displayValue: Double {
        get{
            return Double(display.text!)! // string -> double
        }
        set{
            display.text = String(newValue) // double -> string
        }
    }
    
    //controller가 model에 접근하는 방법, 객체를 생성후 .으로 이용
    private var brain = CalculatorBrain() //클래스의 인스턴스 생성
    
    @IBAction private  func perfromOperation(_ sender: UIButton) {
        if userIsInTheMiddleOfTyping {
            brain.setOperand(operand: displayValue)
            userIsInTheMiddleOfTyping = false
        }
        if let mathmaticalSymbol = sender.currentTitle {
            brain.performOperation(symbol: mathmaticalSymbol)
        }
        displayValue = brain.result
    }
    
}
