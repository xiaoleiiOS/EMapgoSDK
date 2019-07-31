#import <Foundation/Foundation.h>

#import "MGLFoundation.h"
#import "MGLStyleLayer.h"

#import "MGLTypes.h"

@class MGLSource;
@class MGLLight;

NS_ASSUME_NONNULL_BEGIN

/**
 A version number identifying the default version of the EMapgo style.

 @warning The value of this constant may change in a future release of the SDK.
    If you use any feature that depends on a specific aspect of a default style
    — for instance, the minimum zoom level that includes roads — you may use the
    current value of this constant or the underlying style URL, but do not use
    the constant itself. Such details may change significantly from version to
    version.
 */
static MGL_EXPORT const NSInteger MGLStyleDefaultVersion = 11;

FOUNDATION_EXTERN MGL_EXPORT MGLExceptionName const MGLInvalidStyleURLException;
FOUNDATION_EXTERN MGL_EXPORT MGLExceptionName const MGLRedundantLayerException;
FOUNDATION_EXTERN MGL_EXPORT MGLExceptionName const MGLRedundantLayerIdentifierException;
FOUNDATION_EXTERN MGL_EXPORT MGLExceptionName const MGLRedundantSourceException;
FOUNDATION_EXTERN MGL_EXPORT MGLExceptionName const MGLRedundantSourceIdentifierException;

/**
 The proxy object for the current map style.

 MGLStyle provides a set of convenience methods for changing EMapgo
 default styles using `MGLMapView.styleURL`.

 It is also possible to directly manipulate the current map style
 via `MGLMapView.style` by updating the style's data sources or layers.

 @note Wait until the map style has finished loading before modifying a map's
    style via any of the `MGLStyle` instance methods below. You can use the
    `-[MGLMapViewDelegate mapView:didFinishLoadingStyle:]` or
    `-[MGLMapViewDelegate mapViewDidFinishLoadingMap:]` methods as indicators
    that it's safe to modify the map's style.
 */
MGL_EXPORT
@interface MGLStyle : NSObject

#pragma mark Accessing Default Styles

/**
 Returns the URL to the current

 Streets is a general-purpose style with detailed road and transit networks.

 @warning The return value may change in a future release of the SDK. If you use
    any feature that depends on a specific aspect of a default style — for
    instance, the minimum zoom level that includes roads — use the
    `+streetsStyleURLWithVersion:` method instead. Such details may change
    significantly from version to version.
 */
@property (class, nonatomic, readonly) NSURL *streetsStyleURL;

/**
 Returns the URL to the given

 Streets is a general-purpose style with detailed road and transit networks.

 @param version A specific version of the style.
 */
+ (NSURL *)streetsStyleURLWithVersion:(NSInteger)version;

/**
 Returns the URL to the current

 Outdoors is a general-purpose style tailored to outdoor activities.

 @warning The return value may change in a future release of the SDK. If you use
    any feature that depends on a specific aspect of a default style — for
    instance, the minimum zoom level that includes roads — use the
    `+outdoorsStyleURLWithVersion:` method instead. Such details may change
    significantly from version to version.
 */
@property (class, nonatomic, readonly) NSURL *outdoorsStyleURL;

/**
 Returns the URL to the given
 Outdoors is a general-purpose style tailored to outdoor activities.

 @param version A specific version of the style.
 */
+ (NSURL *)outdoorsStyleURLWithVersion:(NSInteger)version;

/**
 Returns the URL to the current

 Light is a subtle, light-colored backdrop for data visualizations.

 @warning The return value may change in a future release of the SDK. If you use
    any feature that depends on a specific aspect of a default style — for
    instance, the minimum zoom level that includes roads — use the
    `+lightStyleURLWithVersion:` method instead. Such details may change
    significantly from version to version.
 */
@property (class, nonatomic, readonly) NSURL *lightStyleURL;

/**
 Returns the URL to the given

 Light is a subtle, light-colored backdrop for data visualizations.

 @param version A specific version of the style.
 */
+ (NSURL *)lightStyleURLWithVersion:(NSInteger)version;

/**
 Returns the URL to the current
 
 Dark is a subtle, dark-colored backdrop for data visualizations.

 @warning The return value may change in a future release of the SDK. If you use
    any feature that depends on a specific aspect of a default style — for
    instance, the minimum zoom level that includes roads — use the
    `+darkStyleURLWithVersion:` method instead. Such details may change
    significantly from version to version.
 */
@property (class, nonatomic, readonly) NSURL *darkStyleURL;

/**
 Returns the URL to the given

 Dark is a subtle, dark-colored backdrop for data visualizations.

 @param version A specific version of the style.
 */
+ (NSURL *)darkStyleURLWithVersion:(NSInteger)version;

/**
 Returns the URL to the current

 Satellite is high-resolution satellite and aerial imagery.

 @warning The return value may change in a future release of the SDK. If you use
    any feature that depends on a specific aspect of a default style — for
    instance, the raster tile sets included in the style — use the
    `+satelliteStyleURLWithVersion:` method instead. Such details may change
    significantly from version to version.
 */
@property (class, nonatomic, readonly) NSURL *satelliteStyleURL;

/**
 Returns the URL to the given

 Satellite is high-resolution satellite and aerial imagery.

 @param version A specific version of the style.
 */
+ (NSURL *)satelliteStyleURLWithVersion:(NSInteger)version;

/**
 Returns the URL to the current

 @warning The return value may change in a future release of the SDK. If you use
    any feature that depends on a specific aspect of a default style — for
    instance, the minimum zoom level that includes roads — use the
    `+satelliteStreetsStyleURLWithVersion:` method instead. Such details may
    change significantly from version to version.
 */
@property (class, nonatomic, readonly) NSURL *satelliteStreetsStyleURL;

/**
 Returns the URL to the given

 @param version A specific version of the style.
 */
+ (NSURL *)satelliteStreetsStyleURLWithVersion:(NSInteger)version;

#pragma mark Accessing Metadata About the Style

/**
 The name of the style.

 You can customize the style’s name in EMapgo Studio.
 */
@property (readonly, copy, nullable) NSString *name;

#pragma mark Managing Sources

/**
 A set containing the style’s sources.
 */
@property (nonatomic, strong) NSSet<__kindof MGLSource *> *sources;

/**
 Values describing animated transitions to changes on a style's individual
 paint properties.
 */
@property (nonatomic) MGLTransition transition;

/**
 A boolean value indicating whether label placement transitions are enabled.

 The default value of this property is `YES`.
 */
@property (nonatomic, assign) BOOL performsPlacementTransitions;

/**
 Returns a source with the given identifier in the current style.

 @note Source identifiers are not guaranteed to exist across styles or different
    versions of the same style. Applications that use this API must first set the
    style URL to an explicitly versioned style using a convenience method like
    `+[MGLStyle outdoorsStyleURLWithVersion:]`, `MGLMapView`’s “Style URL”
    inspectable in Interface Builder, or a manually constructed `NSURL`. This
    approach also avoids source identifer name changes that will occur in the default
    style’s sources over time.

 @return An instance of a concrete subclass of `MGLSource` associated with the
    given identifier, or `nil` if the current style contains no such source.
 */
- (nullable MGLSource *)sourceWithIdentifier:(NSString *)identifier;

/**
 Adds a new source to the current style.

 @note Adding the same source instance more than once will result in a
    `MGLRedundantSourceException`. Reusing the same source identifier, even with
    different source instances, will result in a
    `MGLRedundantSourceIdentifierException`.

 @note Sources should be added in
    `-[MGLMapViewDelegate mapView:didFinishLoadingStyle:]` or
    `-[MGLMapViewDelegate mapViewDidFinishLoadingMap:]` to ensure that the map
    has loaded the style and is ready to accept a new source.

 @param source The source to add to the current style.
 */
- (void)addSource:(MGLSource *)source;

/**
 Removes a source from the current style.

 @note Source identifiers are not guaranteed to exist across styles or different
    versions of the same style. Applications that use this API must first set the
    style URL to an explicitly versioned style using a convenience method like
    `+[MGLStyle outdoorsStyleURLWithVersion:]`, `MGLMapView`’s “Style URL”
    inspectable in Interface Builder, or a manually constructed `NSURL`. This
    approach also avoids source identifer name changes that will occur in the default
    style’s sources over time.

 @param source The source to remove from the current style.
 */
- (void)removeSource:(MGLSource *)source;

/**
 Removes a source from the current style.

 @note Source identifiers are not guaranteed to exist across styles or different
 versions of the same style. Applications that use this API must first set the
 style URL to an explicitly versioned style using a convenience method like
 `+[MGLStyle outdoorsStyleURLWithVersion:]`, `MGLMapView`’s “Style URL”
 inspectable in Interface Builder, or a manually constructed `NSURL`. This
 approach also avoids source identifer name changes that will occur in the default
 style’s sources over time.

 @param source The source to remove from the current style.
 @param outError Upon return, if an error has occurred, a pointer to an `NSError`
 object describing the error. Pass in `NULL` to ignore any error.

 @return `YES` if `source` was removed successfully. If `NO`, `outError` contains
 an `NSError` object describing the problem.
 */
- (BOOL)removeSource:(MGLSource *)source error:(NSError * __nullable * __nullable)outError;


#pragma mark Managing Style Layers

/**
 The layers included in the style, arranged according to their back-to-front
 ordering on the screen.
 */
@property (nonatomic, strong) NSArray<__kindof MGLStyleLayer *> *layers;

/**
 Returns a style layer with the given identifier in the current style.

 @note Layer identifiers are not guaranteed to exist across styles or different
    versions of the same style. Applications that use this API must first set
    the style URL to an explicitly versioned style using a convenience method like
    `+[MGLStyle outdoorsStyleURLWithVersion:]`, `MGLMapView`’s “Style URL”
    inspectable in Interface Builder, or a manually constructed `NSURL`. This
    approach also avoids layer identifer name changes that will occur in the default
    style’s layers over time.

 @return An instance of a concrete subclass of `MGLStyleLayer` associated with
    the given identifier, or `nil` if the current style contains no such style
    layer.
 */
- (nullable MGLStyleLayer *)layerWithIdentifier:(NSString *)identifier;

/**
 Adds a new layer on top of existing layers.

 @note Adding the same layer instance more than once will result in a
    `MGLRedundantLayerException`. Reusing the same layer identifer, even with
    different layer instances, will also result in an exception.

 @note Layers should be added in
    `-[MGLMapViewDelegate mapView:didFinishLoadingStyle:]` or
    `-[MGLMapViewDelegate mapViewDidFinishLoadingMap:]` to ensure that the map
    has loaded the style and is ready to accept a new layer.

 @param layer The layer object to add to the map view. This object must be an
    instance of a concrete subclass of `MGLStyleLayer`.
 */
- (void)addLayer:(MGLStyleLayer *)layer;

/**
 Inserts a new layer into the style at the given index.

 @note Adding the same layer instance more than once will result in a
    `MGLRedundantLayerException`. Reusing the same layer identifer, even with
    different layer instances, will also result in an exception.

 @note Layers should be added in
    `-[MGLMapViewDelegate mapView:didFinishLoadingStyle:]` or
    `-[MGLMapViewDelegate mapViewDidFinishLoadingMap:]` to ensure that the map
    has loaded the style and is ready to accept a new layer.

 @param layer The layer to insert.
 @param index The index at which to insert the layer. An index of 0 would send
    the layer to the back; an index equal to the number of objects in the
    `layers` property would bring the layer to the front.
 */
- (void)insertLayer:(MGLStyleLayer *)layer atIndex:(NSUInteger)index;

/**
 Inserts a new layer below another layer.

 @note Layer identifiers are not guaranteed to exist across styles or different
    versions of the same style. Applications that use this API must first set
    the style URL to an explicitly versioned style using a convenience method like
    `+[MGLStyle outdoorsStyleURLWithVersion:]`, `MGLMapView`’s “Style URL”
    inspectable in Interface Builder, or a manually constructed `NSURL`. This
    approach also avoids layer identifer name changes that will occur in the default
    style’s layers over time.

    Inserting the same layer instance more than once will result in a
    `MGLRedundantLayerException`. Reusing the same layer identifer, even with
    different layer instances, will also result in an exception.

 @param layer The layer to insert.
 @param sibling An existing layer in the style.
 */
- (void)insertLayer:(MGLStyleLayer *)layer belowLayer:(MGLStyleLayer *)sibling;

/**
 Inserts a new layer above another layer.

 @note Layer identifiers are not guaranteed to exist across styles or different
    versions of the same style. Applications that use this API must first set
    the style URL to an explicitly versioned style using a convenience method like
    `+[MGLStyle outdoorsStyleURLWithVersion:]`, `MGLMapView`’s “Style URL”
    inspectable in Interface Builder, or a manually constructed `NSURL`. This
    approach also avoids layer identifer name changes that will occur in the default
    style’s layers over time.

    Inserting the same layer instance more than once will result in a
    `MGLRedundantLayerException`. Reusing the same layer identifer, even with
    different layer instances, will also result in an exception.

 @param layer The layer to insert.
 @param sibling An existing layer in the style.
 */
- (void)insertLayer:(MGLStyleLayer *)layer aboveLayer:(MGLStyleLayer *)sibling;

/**
 Removes a layer from the map view.

 @note Layer identifiers are not guaranteed to exist across styles or different
    versions of the same style. Applications that use this API must first set
    the style URL to an explicitly versioned style using a convenience method like
    `+[MGLStyle outdoorsStyleURLWithVersion:]`, `MGLMapView`’s “Style URL”
    inspectable in Interface Builder, or a manually constructed `NSURL`. This
    approach also avoids layer identifer name changes that will occur in the default
    style’s layers over time.

 @param layer The layer object to remove from the map view. This object
 must conform to the `MGLStyleLayer` protocol.
 */
- (void)removeLayer:(MGLStyleLayer *)layer;

#pragma mark Managing a Style’s Images

/**
 Returns the image associated with the given name in the style.

 @note Names and their associated images are not guaranteed to exist across
    styles or different versions of the same style. Applications that use this
    API must first set the style URL to an explicitly versioned style using a
    convenience method like `+[MGLStyle outdoorsStyleURLWithVersion:]`,
    `MGLMapView`’s “Style URL” inspectable in Interface Builder, or a manually
    constructed `NSURL`. This approach also avoids image name changes that will
    occur in the default style over time.

 @param name The name associated with the image you want to obtain.
 @return The image associated with the given name, or `nil` if no image is
    associated with that name.
 */
- (nullable MGLImage *)imageForName:(NSString *)name;

/**
 Adds or overrides an image used by the style’s layers.

 To use an image in a style layer, give it a unique name using this method, then
 set the `iconImageName` property of an `MGLSymbolStyleLayer` object to that
 name.

 @param image The image for the name.
 @param name The name of the image to set to the style.
 */
- (void)setImage:(MGLImage *)image forName:(NSString *)name;

/**
 Removes a name and its associated image from the style.

 @note Names and their associated images are not guaranteed to exist across
    styles or different versions of the same style. Applications that use this
    API must first set the style URL to an explicitly versioned style using a
    convenience method like `+[MGLStyle outdoorsStyleURLWithVersion:]`,
    `MGLMapView`’s “Style URL” inspectable in Interface Builder, or a manually
    constructed `NSURL`. This approach also avoids image name changes that will
    occur in the default style over time.

 @param name The name of the image to remove.
 */
- (void)removeImageForName:(NSString *)name;


#pragma mark Managing the Style's Light

/**
 Provides global light source for the style.
 */
@property (nonatomic, strong) MGLLight *light;

#pragma mark Localizing Map Content

/**
 Attempts to localize labels in the style into the given locale.

 @param locale The locale into which labels should be localized. To use the
    system’s preferred language, if supported, specify `nil`. To use the local
    language, specify a locale with the identifier `mul`.
 */
- (void)localizeLabelsIntoLocale:(nullable NSLocale *)locale;

@end

NS_ASSUME_NONNULL_END
