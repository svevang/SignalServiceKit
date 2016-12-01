//  Created by Michael Kirk on 12/1/16.
//  Copyright © 2016 Open Whisper Systems. All rights reserved.

#import "TSOutgoingMessage.h"

NS_ASSUME_NONNULL_BEGIN

@class OWSCallOfferMessage;

@interface OWSOutgoingCallMessage : TSOutgoingMessage

- (instancetype)initWithOfferMessage:(OWSCallOfferMessage *)offerMessage;

@property (nullable, nonatomic, readonly, strong) OWSCallOfferMessage *offerMessage;

@end

NS_ASSUME_NONNULL_END
