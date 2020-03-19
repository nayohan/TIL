//
//  ViewController.m
//  MiniBrowser
//
//  Created by NAYOHAN on 2020/03/19.
//  Copyright © 2020 NAYOHAN. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController
@synthesize mainWebView, urlTextField, bookmarkSegmentedControl, activityIndicatorView;

- (void)viewDidLoad {
    [super viewDidLoad];
    NSString * urlString = @"http://www.facebook.com";
    [mainWebView loadRequest: [NSURLRequest requestWithURL:	[NSURL URLWithString: @"http://facebook.com"]]];
    urlTextField.text = urlString;
}

//textField Delegate Protocol
- (BOOL)textFieldShouldReturn:(UITextField *)textField{
    NSString * urlString = urlTextField.text;
    if (![urlString hasPrefix: @"http://"]){
        urlString = [[NSString alloc] initWithFormat:@"http://%@", urlString];
    }
    [mainWebView loadRequest: [NSURLRequest requestWithURL:    [NSURL URLWithString: urlString]]];
    return YES;
}


- (IBAction)bookmarkAction:(id)sender {
    NSString * bookmarkUrl = [bookmarkSegmentedControl titleForSegmentAtIndex: bookmarkSegmentedControl.selectedSegmentIndex];
    NSString * urlString = [[NSString alloc]initWithFormat: @"http://www.%@.com",bookmarkUrl];
    [mainWebView loadRequest: [NSURLRequest requestWithURL:    [NSURL URLWithString: urlString]]];
    urlTextField.text = urlString;
}

- (IBAction)backAction:(id)sender {
    [mainWebView goBack];
}
- (IBAction)forwardAction:(id)sender {
    [mainWebView goForward];
}
- (IBAction)stopAction:(id)sender {
    [mainWebView stopLoading];
}
- (IBAction)refreshAction:(id)sender {
    [mainWebView reload];
}


-(void)webViewDidStartLoad:(UIWebView *)webView {
     [activityIndicatorView startAnimating];
}
-(void)webViewDidFinishLoad:(UIWebView *)webView{
    [activityIndicatorView stopAnimating];
}
@end
