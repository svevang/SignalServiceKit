//  Created by Michael Kirk on 12/1/16.
//  Copyright © 2016 Open Whisper Systems. All rights reserved.

#import "OWSOutgoingCallMessage.h"
#import "OWSCallOfferMessage.h"
#import "OWSCallAnswerMessage.h"
#import "OWSCallIceUpdateMessage.h"
#import "OWSSignalServiceProtos.pb.h"

NS_ASSUME_NONNULL_BEGIN

@implementation OWSOutgoingCallMessage

@synthesize thread = _thread;

- (instancetype)initWithThread:(TSThread *)thread offerMessage:(OWSCallOfferMessage *)offerMessage
{
    self = [super init];
    if (!self) {
        return self;
    }

    _thread = thread;
    _offerMessage = offerMessage;

    return self;
}

- (instancetype)initWithThread:(TSThread *)thread answerMessage:(OWSCallAnswerMessage *)answerMessage
{
    self = [super init];
    if (!self) {
        return self;
    }

    _thread = thread;
    _answerMessage = answerMessage;

    return self;
}

- (instancetype)initWithThread:(TSThread *)thread iceUpdateMessage:(OWSCallIceUpdateMessage *)iceUpdateMessage
{
    self = [super init];
    if (!self) {
        return self;
    }

    _thread = thread;
    _iceUpdateMessage = iceUpdateMessage;

    return self;
}

- (BOOL)shouldSyncTranscript
{
    return NO;
}

- (BOOL)isLegacyMessage
{
    return NO;
}

/**
 * override thread accessor in superclass, since this model is never saved.
 * TODO review
 */
- (TSThread *)thread
{
    return _thread;
}

- (NSData *)buildPlainTextData
{
    OWSSignalServiceProtosContentBuilder *contentBuilder = [OWSSignalServiceProtosContentBuilder new];
    [contentBuilder setCallMessage:[self asProtobuf]];

    return [[contentBuilder build] data];
}

- (OWSSignalServiceProtosCallMessage *)asProtobuf
{
    OWSSignalServiceProtosCallMessageBuilder *builder = [OWSSignalServiceProtosCallMessageBuilder new];

    if (self.offerMessage) {
        [builder setOffer:[self.offerMessage asProtobuf]];
    }

    if (self.answerMessage) {
        [builder setAnswer:[self.answerMessage asProtobuf]];
    }

    return [builder build];
}

#pragma mark - TSYapDatabaseObject overrides

- (void)saveWithTransaction:(YapDatabaseReadWriteTransaction *)transaction
{
    // override superclass with no-op.
    //
    // There's no need to save this message, since it's not displayed to the user.
    //
    // Should we find a need to save this in the future, we need to exclude any non-serializable properties.
}


@end

NS_ASSUME_NONNULL_END
