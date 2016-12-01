//  Created by Michael Kirk on 12/1/16.
//  Copyright © 2016 Open Whisper Systems. All rights reserved.

#import "OWSCallOfferMessage.h"
#import "OWSSignalServiceProtos.pb.h"

NS_ASSUME_NONNULL_BEGIN

@implementation OWSCallOfferMessage

- (instancetype)initWithCallId:(UInt64)callId sessionDescription:(NSString *)sessionDescription
{
    self = [super init];
    if (!self) {
        return self;
    }

    _callId = callId;
    _sessionDescription = sessionDescription;

    return self;
}

- (OWSSignalServiceProtosCallMessageOffer *)asProtobuf
{
    OWSSignalServiceProtosCallMessageOfferBuilder *builder = [OWSSignalServiceProtosCallMessageOfferBuilder new];

    builder.id = self.callId;
    builder.description = self.description;

    return [builder build];
}

@end

NS_ASSUME_NONNULL_END
