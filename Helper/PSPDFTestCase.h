//
//  PSPDFTestCase.h
//  UITestingComparison
//
//  Copyright © 2016 PSPDFKit GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <XCTest/XCTestCase.h>
#import "PSPDFTestAdditions.h"

typedef NS_ENUM(NSUInteger, PSPDFTestCaseSpeed) {
    PSPDFTestCaseSpeedNormal = 1,
    PSPDFTestCaseSpeedCI = 10,
    PSPDFTestCaseSpeedLudicrous = 100
};

NS_ASSUME_NONNULL_BEGIN

@interface PSPDFTestCase : XCTestCase

/// Test running speed. Sets CALayer.speed property on keyWindow's layer.
@property (nonatomic) PSPDFTestCaseSpeed speed;

/// Default test running speed. Depends on whether runing on CI or not.
@property (nonatomic, class, readonly) PSPDFTestCaseSpeed defaultSpeed;

/// Pushes and pops a view controller.
- (void)testWithViewController:(UIViewController *)viewController testBlock:(nullable NS_NOESCAPE dispatch_block_t)testBlock;

/// Pushes a new controller packed in a navigation controller on the root view controller.
- (UINavigationController *)presentViewController:(UIViewController *)viewController;

/// Dismisses a view controller and waits until it's gone.
- (void)dismissViewController:(UIViewController *)viewController;

/// Dismisses a view controller and waits until it's gone with a predefined expectation.
- (void)dismissViewController:(UIViewController *)viewController dismissExpectation:(XCTestExpectation *)dismissExpectation;

@end

NS_ASSUME_NONNULL_END
