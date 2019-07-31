#import <Foundation/Foundation.h>

#import "MGLFoundation.h"

NS_ASSUME_NONNULL_BEGIN

/**
 The `MGLAccountManager` object provides a global way to set a EMapgo API access
 token.
 */
MGL_EXPORT
@interface MGLAccountManager : NSObject

#pragma mark Authorizing Access

/**

 EMapgo-hosted vector tiles and styles require an API access token
 Access tokens associate requests to EMapgo’s vector tile and style APIs with
 your EMapgo account. They also deter other developers from using your styles
 without your permission.

 Setting this property to a value of `nil` has no effect.

 @note You must set the access token before attempting to load any EMapgo-hosted
    style. Therefore, you should generally set it before creating an instance of
    `MGLMapView`. The recommended way to set an access token is to add an entry
    to your application’s Info.plist file with the key `EMapgoAccessToken`
    and the type `String`. Alternatively, you may call this method from your
    application delegate’s `-applicationDidFinishLaunching:` method.
 */
@property (class, nullable) NSString *accessToken;

@end

NS_ASSUME_NONNULL_END
