
#ifndef __CCACTIONTWEEN_H__
#define __CCACTIONTWEEN_H__

#include "game/actions/CGActionInterval.h"

NS_CC_BEGIN

/**
 * @addtogroup actions
 * @{
 */

/**
@brief The delegate class for ActionTween.
@details If you want to use ActionTween on a node.
        You should implement the node follow these steps:
        1. The node should be inherit from ActionTweenDelegate.
        2. Override the virtual method updateTweenAction in the node.

        Then once you running ActionTween on the node, the method updateTweenAction will be invoked.
*/
class CC_DLL ActionTweenDelegate
{
public:
    /**
     * @js NA
     * @lua NA
     */
    virtual ~ActionTweenDelegate() {}

    /**
    @brief The callback function when ActionTween is running.
    @param value The new value of the specified key.
    @param key The key of property which should be updated.
    */
    virtual void updateTweenAction(float value, const std::string& key) = 0;
};

/** ActionTween

 ActionTween is an action that lets you update any property of an object.
 For example, if you want to modify the "width" property of a target from 200 to 300 in 2 seconds, then:

 @code
     auto modifyWidth = ActionTween::create(2, "width", 200, 300);
     target->runAction(modifyWidth);
 @endcode

 Another example: ScaleTo action could be rewritten using PropertyAction:

 @code
     // scaleA and scaleB are equivalents
     auto scaleA = ScaleTo::create(2, 3);                 // (duration, to)
     auto scaleB = ActionTween::create(2, "scale", 1, 3); // (duration, key, from, to)
 @endcode

 @since v0.99.2
 */
class CC_DLL ActionTween : public ActionInterval
{
public:
    /** 
     * @brief Create and initializes the action with the property name (key), and the from and to parameters.
     * @param duration The duration of the ActionTween. It's a value in seconds.
     * @param key The key of property which should be updated.
     * @param from The value of the specified property when the action begin.
     * @param to The value of the specified property when the action end.
     * @return If the creation success, return a pointer of ActionTween; otherwise, return nil.
     */
    static ActionTween* create(float duration, const std::string& key, float from, float to);

    // Overrides
    void startWithTarget(CGNode *target) override;
    void update(float dt) override;
    ActionTween* reverse() const override;
	ActionTween *copy();
    
public:
    /** 
     * @brief Initializes the action with the property name (key), and the from and to parameters.
     * @param duration The duration of the ActionTween. It's a value in seconds.
     * @param key The key of property which should be updated.
     * @param from The value of the specified property when the action begin.
     * @param to The value of the specified property when the action end.
     * @return If the initialization success, return true; otherwise, return false.
     */
    bool initWithDuration(float duration, const std::string& key, float from, float to);

protected:
    std::string       _key;
    float            _from, _to;
    float            _delta;
};

// end of actions group
/// @}

NS_CC_END

#endif /* __CCACTIONTWEEN_H__ */


