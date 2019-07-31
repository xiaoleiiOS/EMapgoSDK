#import "MGLFoundation.h"

#import "MGLRasterTileSource.h"

/**
 An `NSNumber` object containing an unsigned integer that specifies the encoding
 formula for raster-dem tilesets. The integer corresponds to one of
 the constants described in `MGLDEMEncoding`.
 
 The default value for this option is `MGLDEMEncodingMapbox`.
 
 This option cannot be represented in a TileJSON or style JSON file. It is used
 with the `MGLRasterDEMSource` class and is ignored when creating an
 `MGLRasterTileSource` or `MGLVectorTileSource` object.
 */
FOUNDATION_EXTERN MGL_EXPORT const MGLTileSourceOption MGLTileSourceOptionDEMEncoding;

/**
 `MGLRasterDEMSource` is a map content source that supplies rasterized digital elevation model
 (DEM) tiles to be shown on the map. The location of and metadata about the
 tiles are defined either by an option dictionary or by an external file that
 conforms to the TileJSON specification.
 A raster DEM source is added to an `MGLStyle` object along with one or more
 `MGLHillshadeStyleLayer` objects. Use a hillshade style layer to control the
 appearance of content supplied by the raster DEM source.

 ### Example

 ```swift
 let terrainRGBURL = URL(string: "")!
 let source = MGLRasterDEMSource(identifier: "hills", configurationURL: terrainRGBURL)
 mapView.style?.addSource(source)
 ```
 */
MGL_EXPORT
@interface MGLRasterDEMSource : MGLRasterTileSource

@end
