//
//  MJFetcher.h
//
//
//  Created by WangMinjun on 15/8/3.
//
//

#import <Foundation/Foundation.h>
#import "AFNetworking.h"

@class MJSong;
@class MJUserInfo;
@class MJChannel;
@class MJFetcher;

typedef void (^MJFetcherErrorBlock)(MJFetcher* fetcher, NSError* error);
typedef void (^MJFetcherSuccessBlock)(MJFetcher* fetcher, id data);

@interface MJFetcher : NSObject

@property (nonatomic, strong) NSOperation* requestOperation;

+ (MJFetcher*)sharedFetcher;

- (void)fetchPlaylistwithType:(NSString*)type song:(MJSong*)song passedTime:(NSTimeInterval)passedTime channel:(MJChannel*)channel success:(MJFetcherSuccessBlock)successBlock failure:(MJFetcherErrorBlock)errorBlock;

/**
 *  获取验证码图片
 */
- (void)fetchCaptchaImageURLSuccess:(MJFetcherSuccessBlock)successBlock failure:(MJFetcherSuccessBlock)errorBlock;

/**
 *  用户登录
 */
- (void)loginwithUsername:(NSString*)username password:(NSString*)password captcha:(NSString*)captcha captchaID:(NSString*)captchaID rememberOnorOff:(NSString*)rememberOnorOff success:(MJFetcherSuccessBlock)successBlock failure:(MJFetcherErrorBlock)errorBlock;

/**
 *  用户注销
 */
- (void)logoutUser:(MJUserInfo*)userInfo success:(MJFetcherSuccessBlock)successBlock failure:(MJFetcherErrorBlock)errorBlock;

/**
 *  更新 Channel
 */
- (void)fetchChannelWithURL:(NSString*)url success:(MJFetcherSuccessBlock)successBlock failure:(MJFetcherErrorBlock)errorBlock;

/**
 *  添加红心歌曲
 */
- (void)user:(MJUserInfo*)user addHeartSong:(MJSong*)song action:(NSString*)action success:(MJFetcherSuccessBlock)successBlock failure:(MJFetcherErrorBlock)errorBlock;

@end
