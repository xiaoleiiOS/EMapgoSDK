#import <Foundation/Foundation.h>

#import "MGLFoundation.h"
#import "MGLSource.h"
#import "MGLTypes.h"

NS_ASSUME_NONNULL_BEGIN

@class MGLAttributionInfo;

/**
 Options for `MGLTileSource` objects.
 */
typedef NSString *MGLTileSourceOption NS_STRING_ENUM;

/**
 An `NSNumber` object containing an unsigned integer that specifies the minimum
 zoom level at which to display tiles from the source.

 The value should be between 0 and 22, inclusive, and less than
 `MGLTileSourceOptionMaximumZoomLevel`, if specified. The default value for this
 option is 0.
 */
FOUNDATION_EXTERN MGL_EXPORT const MGLTileSourceOption MGLTileSourceOptionMinimumZoomLevel;

/**
 An `NSNumber` object containing an unsigned integer that specifies the maximum
 zoom level at which to display tiles from the source.

 The value should be between 0 and 22, inclusive, and less than
 `MGLTileSourceOptionMinimumZoomLevel`, if specified. The default value for this
 option is 22.
 */
FOUNDATION_EXTERN MGL_EXPORT const MGLTileSourceOption MGLTileSourceOptionMaximumZoomLevel;

/**
 An `NSValue` object containing an `MGLCoordinateBounds` struct that specifies
 the geographic extent of the source.
 
 If this option is specified, the SDK avoids requesting any tile that falls
 outside of the coordinate bounds. Otherwise, the SDK requests any tile needed
 to cover the viewport, as it does by default.
 */
FOUNDATION_EXTERN MGL_EXPORT const MGLTileSourceOption MGLTileSourceOptionCoordinateBounds;

#if TARGET_OS_IPHONE
/**
 An HTML string defining the buttons to be displayed in an action sheet when the
 source is part of a map view’s style and the map view’s attribution button is
 pressed.

 By default, no attribution statements are displayed. If the
 `MGLTileSourceOptionAttributionInfos` option is specified, this option is
 ignored.
 */
FOUNDATION_EXTERN MGL_EXPORT const MGLTileSourceOption MGLTileSourceOptionAttributionHTMLString;

/**
 An array of `MGLAttributionInfo` objects defining the buttons to be displayed
 in an action sheet when the source is part of a map view’s style and the map
 view’s attribution button is pressed.

 By default, no attribution statements are displayed.
 */
FOUNDATION_EXTERN MGL_EXPORT const MGLTileSourceOption MGLTileSourceOptionAttributionInfos;
#else
/**
 An HTML string defining the buttons to be displayed in the map view’s
 attribution view when the source is part of the map view’s style.

 By default, no attribution statements are displayed. If the
 `MGLTileSourceOptionAttributionInfos` option is specified, this option is
 ignored.
 */
FOUNDATION_EXTERN MGL_EXPORT const MGLTileSourceOption MGLTileSourceOptionAttributionHTMLString;

/**
 An array of `MGLAttributionInfo` objects defining the buttons to be displayed
 in the map view’s attribution view when the source is part of the map view’s
 style.

 By default, no attribution statements are displayed.
 */
FOUNDATION_EXTERN MGL_EXPORT const MGLTileSourceOption MGLTileSourceOptionAttributionInfos;
#endif

/**
 An `NSNumber` object containing an unsigned integer that specifies the tile
 coordinate system for the source’s tile URLs. The integer corresponds to one of
 the constants described in `MGLTileCoordinateSystem`.

 The default value for this option is `MGLTileCoordinateSystemXYZ`.
 */
FOUNDATION_EXTERN MGL_EXPORT const MGLTileSourceOption MGLTileSourceOptionTileCoordinateSystem;

/**
 Tile coordinate systems that determine how tile coordinates in tile URLs are
 interpreted.
 */
typedef NS_ENUM(NSUInteger, MGLTileCoordinateSystem) {
    /**
     The origin is at the top-left (northwest), and `y` values increase
     southwards.

     This tile coordinate system is used by EMapgo and OpenStreetMap tile
     servers.
     */
    MGLTileCoordinateSystemXYZ = 0,

    /**
     The origin is at the bottom-left (southwest), and `y` values increase
     northwards.

     This tile coordinate system is used by tile servers that conform to the
     <a href="http://wiki.osgeo.org/wiki/Tile_Map_Service_Specification">Tile Map Service Specification</a>.
     */
    MGLTileCoordinateSystemTMS
};

/**
 The encoding formula used to generate the raster-dem tileset
*/

typedef NS_ENUM(NSUInteger, MGLDEMEncoding) {

    /**
     Raster tiles generated
    */
    MGLDEMEncodingMapbox = 0,

    /**
     Raster tiles generated
    */
    MGLDEMEncodingTerrarium
};

/**
 `MGLTileSource` is a map content source that supplies map tiles to be shown on
 the map.

 Create instances of `MGLRasterTileSource` and `MGLVectorTileSource` in order
 to use `MGLTileSource`'s properties and methods. Do not create instances of
 `MGLTileSource` directly, and do not create your own subclasses of this class.
 */
MGL_EXPORT
@interface MGLTileSource : MGLSource

#pragma mark Accessing a Source’s Content

/**
 The URL to the TileJSON configuration file that specifies the contents of the
 source.

 If the receiver was initialized using
 `-initWithIdentifier:tileURLTemplates:options`, this property is set to `nil`.
 */
@property (nonatomic, copy, nullable, readonly) NSURL *configurationURL;

#pragma mark Accessing Attribution Strings

/**
 An array of `MGLAttributionInfo` objects that define the attribution
 statements to be displayed when the map is shown to the user.

 By default, this array is empty. If the source is initialized with a
 configuration URL, this array is also empty until the configuration JSON file
 is loaded.
 */
@property (nonatomic, copy, readonly) NSArray<MGLAttributionInfo *> *attributionInfos;

@end

NS_ASSUME_NONNULL_END
