//  Created by Michael Kirk on 12/4/16.
//  Copyright © 2016 Open Whisper Systems. All rights reserved.

NS_ASSUME_NONNULL_BEGIN

@class OWSSignalServiceProtosCallMessageOffer;
@class OWSSignalServiceProtosCallMessageAnswer;
@class OWSSignalServiceProtosCallMessageIceUpdate;
@class OWSSignalServiceProtosCallMessageHangup;

@protocol OWSCallMessageHandler <NSObject>

- (void)receivedOffer:(OWSSignalServiceProtosCallMessageOffer *)offer fromCallerId:(NSString *)callerId NS_SWIFT_NAME(receivedOffer(_:from:));
- (void)receivedAnswer:(OWSSignalServiceProtosCallMessageAnswer *)answer fromCallerId:(NSString *)callerId NS_SWIFT_NAME(receivedAnswer(_:from:));
- (void)receivedIceUpdates:(NSArray<OWSSignalServiceProtosCallMessageIceUpdate *> *)iceUpdates fromCallerId:(NSString *)callerId NS_SWIFT_NAME(receivedIceUpdates(_:from:));
- (void)receivedHangup:(OWSSignalServiceProtosCallMessageHangup *)hangup fromCallerId:(NSString *)callerId NS_SWIFT_NAME(receivedHangup(_:from:));

@end

NS_ASSUME_NONNULL_END
