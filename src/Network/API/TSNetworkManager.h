//
//  TSNetworkManager.h
//  TextSecureiOS
//
//  Created by Frederic Jacobs on 9/27/13.
//  Copyright (c) 2013 Open Whisper Systems. All rights reserved.
//

/**
 *  TSNetworkManager imports all TSRequests to prevent massive imports
 in classes that call TSNetworkManager
 */
#import "TSAllocAttachmentRequest.h"
#import "TSAttachmentRequest.h"
#import "TSAvailablePreKeysCountRequest.h"
#import "TSContactsIntersectionRequest.h"
#import "TSCurrentSignedPreKeyRequest.h"
#import "TSRecipientPrekeyRequest.h"
#import "TSRegisterForPushRequest.h"
#import "TSRegisterPrekeysRequest.h"
#import "TSRequestVerificationCodeRequest.h"
#import "TSSubmitMessageRequest.h"
#import "TSUnregisterAccountRequest.h"
#import "TSUpdateAttributesRequest.h"
#import "TSVerifyCodeRequest.h"


#import <AFNetworking/AFHTTPSessionManager.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TSNetworkManager : NSObject

+ (id)sharedManager;

- (void)makeRequest:(TSRequest *)request
            success:(void (^)(NSURLSessionDataTask *task, _Nullable id responseObject))success
            failure:(void (^)(NSURLSessionDataTask *task, NSError *error))failure
    NS_SWIFT_NAME(makeRequest(_:success:failure:));

@end

NS_ASSUME_NONNULL_END
