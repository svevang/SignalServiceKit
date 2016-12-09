//  Created by Michael Kirk on 12/1/16.
//  Copyright © 2016 Open Whisper Systems. All rights reserved.

#import "TSOutgoingMessage.h"

NS_ASSUME_NONNULL_BEGIN

@class OWSCallOfferMessage;
@class OWSCallAnswerMessage;
@class OWSCallIceUpdateMessage;
@class OWSCallHangupMessage;
@class OWSCallBusyMessage;

@class TSThread;

@interface OWSOutgoingCallMessage : TSOutgoingMessage

- (instancetype)initWithThread:(TSThread *)thread offerMessage:(OWSCallOfferMessage *)offerMessage;
- (instancetype)initWithThread:(TSThread *)thread answerMessage:(OWSCallAnswerMessage *)answerMessage;
- (instancetype)initWithThread:(TSThread *)thread iceUpdateMessage:(OWSCallIceUpdateMessage *)iceUpdateMessage;
- (instancetype)initWithThread:(TSThread *)thread
             iceUpdateMessages:(NSArray<OWSCallIceUpdateMessage *> *)iceUpdateMessage;
- (instancetype)initWithThread:(TSThread *)thread hangupMessage:(OWSCallHangupMessage *)hangupMessage;
- (instancetype)initWithThread:(TSThread *)thread busyMessage:(OWSCallBusyMessage *)busyMessage;

@property (nonnull, nonatomic, readonly, strong) TSThread *thread;
@property (nullable, nonatomic, readonly, strong) OWSCallOfferMessage *offerMessage;
@property (nullable, nonatomic, readonly, strong) OWSCallAnswerMessage *answerMessage;
@property (nullable, nonatomic, readonly, strong) NSArray<OWSCallIceUpdateMessage *> *iceUpdateMessages;
@property (nullable, nonatomic, readonly, strong) OWSCallHangupMessage *hangupMessage;
@property (nullable, nonatomic, readonly, strong) OWSCallBusyMessage *busyMessage;

@end

NS_ASSUME_NONNULL_END
