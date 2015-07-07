#import <Foundation/Foundation.h>
#import "KSNullabilityCompat.h"

@class KSPromise<ObjectType>;

NS_ASSUME_NONNULL_BEGIN

@interface KSNetworkResponse : NSObject
@property (strong, nonatomic, readonly) NSURLResponse *response;
@property (strong, nonatomic, readonly) NSData *data;

+ (KSNetworkResponse *)networkResponseWithURLResponse:(NSURLResponse *)response data:(NSData *)data;
@end

@protocol KSNetworkClient <NSObject>

- (KSPromise<KSNetworkResponse *> *)sendAsynchronousRequest:(NSURLRequest *)request queue:(NSOperationQueue *)queue;

@end

// Add a concrete implementation with the old name for backwards compatibility
@interface KSNetworkClient : NSObject <KSNetworkClient>
@end

NS_ASSUME_NONNULL_END
