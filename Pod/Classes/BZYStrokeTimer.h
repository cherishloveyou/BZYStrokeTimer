//
//  BZYStrokeTimer.h
//  Busy
//
//  Created by Rudd Fawcett on 6/11/15.
//  Copyright (c) 2015 Busy, LLC. All rights reserved.
//

@import UIKit;

#import "BZYStrokeTimerDelegate.h"

IB_DESIGNABLE
@interface BZYStrokeTimer : UIView

#pragma mark - Timer Customization

@property (nonatomic) IBInspectable CGFloat progress;
@property (nonatomic) IBInspectable UIColor *timerColor;
@property (nonatomic) IBInspectable CGFloat lineWidth;
/**
 *  Timing function to be used.
 *  @see CAMediaTimingFunction.h
 */
@property (nonatomic) NSString *timingFunction;

/**
 *  Duration of the animation.
 */
@property (nonatomic) NSTimeInterval duration;


#pragma mark - Timer State
/**
 *  The elapsed time of the animation so far.
 */
@property (nonatomic, readonly) NSTimeInterval elapsedTime;
/**
 *  Percent of animation completed. Calculated as elapsedTime/duration;
 */
@property (nonatomic, readonly) CGFloat animationCompletion;
/**
 *  Is the timer currently animating.
 */
@property (nonatomic, getter=isRunning, readonly) BOOL running;
/**
 *  Is the timer paused.
 */
@property (nonatomic, getter=isPaused, readonly)  BOOL paused;

#pragma mark - BZYStrokeTimerDelegate

/**
 *  Delegate object.
 */
@property (nonatomic, weak) id<BZYStrokeTimerDelegate> delegate;

#pragma mark - Animation

/**
 *  Start the timer animation.
 */
- (void)start;

/**
 *  Pause the timer animation.
 */
- (void)pause;

/**
 *  Resume the timer animation.
 */
- (void)resume;

/**
 *  Stops the timer animation. 
 *
 * @note This method will be call automatically once elapsedTime = duration.
 * @warning If you pause the timer, this method must be called to clear the 
 * previous animation.
 */
- (void)stop;

@end
