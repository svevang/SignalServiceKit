//  Created by Michael Kirk on 12/4/16.
//  Copyright © 2016 Open Whisper Systems. All rights reserved.

NS_ASSUME_NONNULL_BEGIN

@class OWSSignalServiceProtosCallMessageOffer;
@class OWSSignalServiceProtosCallMessageAnswer;
@class OWSSignalServiceProtosCallMessageIceUpdate;
@class OWSSignalServiceProtosCallMessageHangup;

@protocol OWSCallMessageHandler <NSObject>

- (void)receivedOffer:(OWSSignalServiceProtosCallMessageOffer *)offer;
- (void)receivedAnswer:(OWSSignalServiceProtosCallMessageAnswer *)answer;
- (void)receivedIceUpdates:(NSArray<OWSSignalServiceProtosCallMessageIceUpdate *> *)iceUpdates;
- (void)receivedHangup:(OWSSignalServiceProtosCallMessageHangup *)hangup;

@end

NS_ASSUME_NONNULL_END
