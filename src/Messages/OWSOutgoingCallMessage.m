//  Created by Michael Kirk on 12/1/16.
//  Copyright © 2016 Open Whisper Systems. All rights reserved.

#import "OWSOutgoingCallMessage.h"
#import "OWSCallOfferMessage.h"
#import "OWSSignalServiceProtos.pb.h"

NS_ASSUME_NONNULL_BEGIN

@implementation OWSOutgoingCallMessage

- (instancetype)initWithOfferMessage:(OWSCallOfferMessage *)offerMessage
{
    self = [super init];
    if (!self) {
        return self;
    }

    _offerMessage = offerMessage;

    return self;
}

- (BOOL)shouldSyncTranscript
{
    return NO;
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
