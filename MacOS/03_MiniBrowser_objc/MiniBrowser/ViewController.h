//
//  ViewController.h
//  MiniBrowser
//
//  Created by NAYOHAN on 2020/03/19.
//  Copyright © 2020 NAYOHAN. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ViewController : UIViewController <UITextFieldDelegate, UIWebViewDelegate> //Delgate Protocol을 준수하겠다.
@property (weak, nonatomic) IBOutlet UISegmentedControl *bookmarkSegmentedControl;
@property (weak, nonatomic) IBOutlet UITextField *urlTextField;
@property (weak, nonatomic) IBOutlet UIWebView *mainWebView;
@property (weak, nonatomic) IBOutlet UIActivityIndicatorView *activityIndicatorView;

- (IBAction)bookmarkAction:(id)sender;

- (IBAction)backAction:(id)sender;
- (IBAction)forwardAction:(id)sender;
- (IBAction)stopAction:(id)sender;
- (IBAction)refreshAction:(id)sender;

@end

