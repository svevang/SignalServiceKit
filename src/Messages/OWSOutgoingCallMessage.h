//  Created by Michael Kirk on 12/1/16.
//  Copyright © 2016 Open Whisper Systems. All rights reserved.

#import "TSOutgoingMessage.h"

NS_ASSUME_NONNULL_BEGIN

@class OWSCallOfferMessage;
@class OWSCallAnswerMessage;
@class TSThread;

@interface OWSOutgoingCallMessage : TSOutgoingMessage

- (instancetype)initWithOfferMessage:(OWSCallOfferMessage *)offerMessage thread:(TSThread *)thread;
- (instancetype)initWithAnswerMessage:(OWSCallAnswerMessage *)answerMessage thread:(TSThread *)thread;

@property (nonnull, nonatomic, readonly, strong) TSThread *thread;
@property (nullable, nonatomic, readonly, strong) OWSCallOfferMessage *offerMessage;
@property (nullable, nonatomic, readonly, strong) OWSCallAnswerMessage *answerMessage;

@end

NS_ASSUME_NONNULL_END
