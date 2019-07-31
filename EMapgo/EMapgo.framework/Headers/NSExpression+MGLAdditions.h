#import <Foundation/Foundation.h>
#if TARGET_OS_IPHONE
    #import <UIKit/UIKit.h>
#else
    #import <Cocoa/Cocoa.h>
#endif

#import "MGLTypes.h"

@class MGLAttributedExpression;

NS_ASSUME_NONNULL_BEGIN

typedef NSString *MGLExpressionInterpolationMode NS_TYPED_ENUM;

/**
 An `NSString` identifying the `linear` interpolation type in an `NSExpression`.
 */
FOUNDATION_EXTERN MGL_EXPORT const MGLExpressionInterpolationMode MGLExpressionInterpolationModeLinear;

/**
 An `NSString` identifying the `expotential` interpolation type in an `NSExpression`.
 
 */
FOUNDATION_EXTERN MGL_EXPORT const MGLExpressionInterpolationMode MGLExpressionInterpolationModeExponential;

/**
 An `NSString` identifying the `cubic-bezier` interpolation type in an `NSExpression`.
 */
FOUNDATION_EXTERN MGL_EXPORT const MGLExpressionInterpolationMode MGLExpressionInterpolationModeCubicBezier;

/**
 Methods for creating expressions that use EMapgo-specific functionality.
 */
@interface NSExpression (MGLAdditions)

#pragma mark Creating Variable Expressions

/**
 `NSExpression` variable that corresponds.
 */
@property (class, nonatomic, readonly) NSExpression *zoomLevelVariableExpression;

/**
 `NSExpression` variable that corresponds.
 */
@property (class, nonatomic, readonly) NSExpression *heatmapDensityVariableExpression;

/**
 `NSExpression` variable that corresponds.
 */
@property (class, nonatomic, readonly) NSExpression *lineProgressVariableExpression;

/**
 `NSExpression` variable that corresponds.
 */
@property (class, nonatomic, readonly) NSExpression *geometryTypeVariableExpression;

/**
 `NSExpression` variable that corresponds.
 */
@property (class, nonatomic, readonly) NSExpression *featureIdentifierVariableExpression;

/**
 `NSExpression` variable that corresponds.
 */
@property (class, nonatomic, readonly) NSExpression *featureAttributesVariableExpression;

@property (class, nonatomic, readonly) NSExpression *featurePropertiesVariableExpression __attribute__((deprecated("", "featureAttributesVariableExpression")));

#pragma mark Creating Conditional Expressions

/**
 Returns a conditional function expression specifying the string predicate, and
 expressions for each condition.
 
 @param conditionPredicate The predicate to get evaluated.
 @param trueExpression The expression for conditions equal to true.
 @param falseExpression The expression for conditions equal to false.
 */
+ (instancetype)mgl_expressionForConditional:(nonnull NSPredicate *)conditionPredicate trueExpression:(nonnull NSExpression *)trueExpression falseExpresssion:(nonnull NSExpression *)falseExpression NS_SWIFT_NAME(init(forMGLConditional:trueExpression:falseExpression:));

#pragma mark Creating Ramp, Scale, and Curve Expressions

/**
 Returns a step function expression specifying the stepping, from expression
 and stops.
 
 @param steppingExpression The stepping expression.
 @param minimumExpression The expression which could be a constant or function expression.
 @param stops The stops must be an `NSDictionary` constant `NSExpression`.
 */
+ (instancetype)mgl_expressionForSteppingExpression:(nonnull NSExpression*)steppingExpression fromExpression:(nonnull NSExpression *)minimumExpression stops:(nonnull NSExpression*)stops NS_SWIFT_NAME(init(forMGLStepping:from:stops:));

/**
 Returns an interpolated function expression specifying the function operator, curve type,
 parameters and steps.
 
 @param inputExpression The interpolating expression input.
 @param curveType The curve type could be `MGLExpressionInterpolationModeLinear`,
 `MGLExpressionInterpolationModeExponential` and
 `MGLExpressionInterpolationModeCubicBezier`.
 @param parameters The parameters expression.
 @param stops The stops expression.
 */
+ (instancetype)mgl_expressionForInterpolatingExpression:(nonnull NSExpression*)inputExpression withCurveType:(nonnull MGLExpressionInterpolationMode)curveType parameters:(nullable NSExpression *)parameters stops:(nonnull NSExpression*)stops NS_SWIFT_NAME(init(forMGLInterpolating:curveType:parameters:stops:));

/**
 Returns a match function expression specifying the input, matching values,
 and default value.
 
 @param inputExpression The matching expression.
 @param matchedExpressions The matched values expression dictionary must be condition : value.
 @param defaultExpression The defaultValue expression to be used in case there is no match.
 */
+ (instancetype)mgl_expressionForMatchingExpression:(nonnull NSExpression *)inputExpression inDictionary:(nonnull NSDictionary<NSExpression *, NSExpression *> *)matchedExpressions defaultExpression:(nonnull NSExpression *)defaultExpression NS_SWIFT_NAME(init(forMGLMatchingKey:in:default:));

/**
 Returns an attributed function expression specifying an `MGLAttributedExpression` constant
 expression array.
 
 @param attributedExpressions The `MGLAttributedExpression` constant expression array.
 */
+ (instancetype)mgl_expressionForAttributedExpressions:(nonnull NSArray<NSExpression *> *)attributedExpressions NS_SWIFT_NAME(init(forAttributedExpressions:));

#pragma mark Concatenating String Expressions

/**
 Returns a constant expression appending the passed expression.
 
 @note Both the receiver and the given expression must be an `NSString` constant
 expression type; otherwise, an exception is rised.
 
 @param expression The expression to append to the receiver.
 */
- (instancetype)mgl_expressionByAppendingExpression:(nonnull NSExpression *)expression NS_SWIFT_NAME(mgl_appending(_:));

#pragma mark Converting JSON Expressions

/**
 Returns an expression equivalent to the given Foundation object deserialized
 from JSON data.
 
 @param object A Foundation object deserialized from JSON data, for example
    using `NSJSONSerialization`.
 @return An initialized expression equivalent to `object`, suitable for use as
    the value of a style layer attribute.
 */
+ (instancetype)expressionWithMGLJSONObject:(id)object NS_SWIFT_NAME(init(mglJSONObject:));

/**
 An equivalent Foundation object that can be serialized as JSON.
 
 You can use `NSJSONSerialization` to serialize the Foundation object as data to
 write to a file.
 */
@property (nonatomic, readonly) id mgl_jsonExpressionObject;

#pragma mark Localizing the Expression

/**
 Returns a copy of the receiver localized into the given locale.
 
 @param locale The locale into which labels should be localized. To use the
    system’s preferred language, if supported, specify `nil`. To use the local
    language, specify a locale with the identifier `mul`.
 */
- (NSExpression *)mgl_expressionLocalizedIntoLocale:(nullable NSLocale *)locale;

@end

NS_ASSUME_NONNULL_END
