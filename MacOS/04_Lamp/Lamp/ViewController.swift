//
//  ViewController.swift
//  Lamp
//
//  Created by NAYOHAN on 2020/04/13.
//  Copyright © 2020 NAYOHAN. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    var isZoom = false
    let imgOn = UIImage(named: "lamp_on.png")
    let imgOff = UIImage(named: "lamp_off.png")
    let imgRemove = UIImage(named: "lamp-remove.png")
    var isLampOn = true
    
    @IBOutlet weak var imgView: UIImageView!
    @IBOutlet weak var btnResize: UIButton!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        imgView.image = imgOn
    }

    @IBAction func btnResizeImage(_ sender: UIButton) {
        let scale: CGFloat = 2.0
        var newWidth: CGFloat, newHeight: CGFloat
        if (isZoom) {
            newWidth = imgView.frame.width/scale
            newHeight = imgView.frame.height/scale
            btnResize.setTitle("확대", for: .normal)
        }
        else {
            newWidth = imgView.frame.width*scale
            newHeight = imgView.frame.height*scale
            btnResize.setTitle("축소", for: .normal)
        }
        imgView.frame.size = CGSize(width: newWidth, height: newHeight)
        isZoom = !isZoom
    }
    
    @IBAction func btnLampOn(_ sender: UIButton) {
        if isLampOn{
            //램프가 이미 켜져있음
            let lampOnAlert = UIAlertController(title: "경고", message: "현재 On 상태입니다", preferredStyle: UIAlertController.Style.alert)
            let onAction = UIAlertAction(title: "네, 알겠습니다", style: UIAlertAction.Style.default, handler: nil)
            lampOnAlert.addAction(onAction)
            present(lampOnAlert, animated: true, completion: nil)
        }
        else{
            imgView.image = imgOn
            isLampOn = true
        }
    }
    @IBAction func btnLampOff(_ sender: UIButton) {
        if isLampOn{
            imgView.image = imgOff
            isLampOn = false
        }
        else{
            //램프가 이미 꺼져있을때 알림
        }
    }
    @IBAction func btnLampRemove(_ sender: UIButton) {
        imgView.image = imgRemove
    }
}
