#import <CoreGraphics/CoreGraphics.h>

#import "MGLFoundation.h"
#import "MGLTileSource.h"

NS_ASSUME_NONNULL_BEGIN

/**
 An `NSNumber` object containing a floating-point number that specifies the
 width and height (measured in points) at which the map displays each raster
 image tile when the map’s zoom level is an integer. The raster tile source
 scales its images up or down when the map’s zoom level falls between two
 integers.

 This option is only applicable to `MGLRasterTileSource` objects; it is ignored
 when initializing `MGLVectorTileSource` objects.
 */
FOUNDATION_EXTERN MGL_EXPORT const MGLTileSourceOption MGLTileSourceOptionTileSize;

/**
 `MGLRasterTileSource` is a map content source that supplies raster image tiles
 to be shown on the map. The location of and metadata about the tiles are
 defined either by an option dictionary or by an external file that conforms to
 the TileJSON specification.
 A raster tile source is added to an `MGLStyle` object along with one or more
 `MGLRasterStyleLayer` objects. Use a raster style layer to control the
 appearance of content supplied by the raster tile source.

 ### Example

 ```swift
 mapView.style?.addSource(source)
 ```
 */
MGL_EXPORT
@interface MGLRasterTileSource : MGLTileSource

#pragma mark Initializing a Source

/**
 Returns a raster tile source initialized with an identifier and configuration
 URL.

 After initializing and configuring the source, add it to a map view’s style
 using the `-[MGLStyle addSource:]` method.

 If a EMapgo URL is specified, this source uses a tile size of 256. For all
 other tilesets, the default value is 512. (See the
 `MGLTileSourceOptionTileSize` documentation for more information about tile
 sizes.) If you need to use a tile size other than the default, use the
 `-initWithIdentifier:configurationURL:tileSize:` method.

 @param identifier A string that uniquely identifies the source in the style to
    which it is added.
 @param configurationURL A URL to a TileJSON configuration file describing the
    source’s contents and other metadata.
 @return An initialized raster tile source.
 */
- (instancetype)initWithIdentifier:(NSString *)identifier configurationURL:(NSURL *)configurationURL;

/**
 Returns a raster tile source initialized with an identifier, configuration URL,
 and tile size.

 After initializing and configuring the source, add it to a map view’s style
 using the `-[MGLStyle addSource:]` method.

 @param identifier A string that uniquely identifies the source in the style to
    which it is added.
 @param configurationURL A URL to a TileJSON configuration file describing the
 source’s contents and other metadata.
 @param tileSize The width and height (measured in points) of each tiled image
    in the raster tile source. See the `MGLTileSourceOptionTileSize`
    documentation for details.
 @return An initialized raster tile source.
 */
- (instancetype)initWithIdentifier:(NSString *)identifier configurationURL:(NSURL *)configurationURL tileSize:(CGFloat)tileSize NS_DESIGNATED_INITIALIZER;

/**
 Returns a raster tile source initialized an identifier, tile URL templates, and
 options.

 Tile URL templates are strings that specify the URLs of the raster tile images
 to load. See the “<a href="../tile-url-templates.html">Tile URL Templates</a>”
 guide for information about the format of a tile URL template.

 After initializing and configuring the source, add it to a map view’s style
 using the `-[MGLStyle addSource:]` method.

 @param identifier A string that uniquely identifies the source in the style to
    which it is added.
 @param tileURLTemplates An array of tile URL template strings. Only the first
    string is used; any additional strings are ignored.
 @param options A dictionary containing configuration options. See
    `MGLTileSourceOption` for available keys and values. Pass in `nil` to use
    the default values.
 @return An initialized tile source.
 */
- (instancetype)initWithIdentifier:(NSString *)identifier tileURLTemplates:(NSArray<NSString *> *)tileURLTemplates options:(nullable NSDictionary<MGLTileSourceOption, id> *)options NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
