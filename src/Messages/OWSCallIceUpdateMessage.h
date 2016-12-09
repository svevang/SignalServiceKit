//  Created by Michael Kirk on 12/6/16.
//  Copyright © 2016 Open Whisper Systems. All rights reserved.


NS_ASSUME_NONNULL_BEGIN

@class OWSSignalServiceProtosCallMessageIceUpdate;

@interface OWSCallIceUpdateMessage : NSObject

@property (nonatomic, readonly) UInt64 callId;
@property (nonatomic, readonly, copy) NSString *sdp;
@property (nonatomic, readonly) SInt32 sdpMLineIndex;
@property (nullable, nonatomic, readonly, copy) NSString *sdpMid;

- (instancetype)initWithCallId:(UInt64)callId
                           sdp:(NSString *)sdp
                 sdpMLineIndex:(SInt32)sdpMLineIndex
                        sdpMid:(nullable NSString *)sdpMid;

- (OWSSignalServiceProtosCallMessageIceUpdate *)asProtobuf;

@end

NS_ASSUME_NONNULL_END
