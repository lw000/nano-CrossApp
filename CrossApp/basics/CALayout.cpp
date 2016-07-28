

#include "CALayout.h"
#include "ccMacros.h"
#include "basics/CAApplication.h"

NS_CC_BEGIN

#define F_ACCURACY 0.001f
#define fround(_x_) (((int)(_x_ > FLT_EPSILON ? (_x_ * 1000 + 0.5) : (_x_ * 1000 - 0.5))) / 1000.0f)

DHorizontalLayout::DHorizontalLayout()
:left(FLOAT_NONE)
,right(FLOAT_NONE)
,width(FLOAT_NONE)
,center(FLOAT_NONE)
,normalizedWidth(FLOAT_NONE)
{

}

DHorizontalLayout::DHorizontalLayout(const DHorizontalLayout& other)
:left(other.left)
,right(other.right)
,width(other.width)
,center(other.center)
,normalizedWidth(other.normalizedWidth)
{
    
}

DHorizontalLayout::DHorizontalLayout(float var1, float var2, const Type& type)
:left(FLOAT_NONE)
,right(FLOAT_NONE)
,width(FLOAT_NONE)
,center(FLOAT_NONE)
,normalizedWidth(FLOAT_NONE)
{
    switch (type)
    {
        case L_R:
        {
            left = var1;
            right = var2;
        }
            break;
        case L_W:
        {
            left = var1;
            width = var2;
        }
            break;
        case L_C:
        {
            left = var1;
            center = var2;
        }
            break;
        case R_W:
        {
            right = var1;
            width = var2;
        }
            break;
        case R_C:
        {
            right = var1;
            center = var2;
        }
            break;
        case W_C:
        {
            width = var1;
            center = var2;
        }
            break;
        case C_NW:
        {
            center = var1;
            normalizedWidth = var2;
        }
            break;
        default:
            break;
    }
}

DHorizontalLayout& DHorizontalLayout::operator= (const DHorizontalLayout& other)
{
    left = other.left;
    right = other.right;
    width = other.width;
    center = other.center;
    normalizedWidth = other.normalizedWidth;
    return *this;
}

bool DHorizontalLayout::equals(const DHorizontalLayout& target) const
{
    return (fabs(left - target.left) < F_ACCURACY)
        && (fabs(right - target.right) < F_ACCURACY)
        && (fabs(width - target.width) < F_ACCURACY)
        && (fabs(center - target.center) < F_ACCURACY)
        && (fabs(normalizedWidth - target.normalizedWidth) < F_ACCURACY);
}



DVerticalLayout::DVerticalLayout()
:top(FLOAT_NONE)
,bottom(FLOAT_NONE)
,height(FLOAT_NONE)
,center(FLOAT_NONE)
,normalizedHeight(FLOAT_NONE)
{
    
}

DVerticalLayout::DVerticalLayout(const DVerticalLayout& other)
:top(other.top)
,bottom(other.bottom)
,height(other.height)
,center(other.center)
,normalizedHeight(other.normalizedHeight)
{
    
}

DVerticalLayout::DVerticalLayout(float var1, float var2, const Type& type)
:top(FLOAT_NONE)
,bottom(FLOAT_NONE)
,height(FLOAT_NONE)
,center(FLOAT_NONE)
,normalizedHeight(FLOAT_NONE)
{
    switch (type)
    {
        case T_B:
        {
            top = var1;
            bottom = var2;
        }
            break;
        case T_H:
        {
            top = var1;
            height = var2;
        }
            break;
        case T_C:
        {
            top = var1;
            center = var2;
        }
            break;
        case B_H:
        {
            bottom = var1;
            height = var2;
        }
            break;
        case B_C:
        {
            bottom = var1;
            center = var2;
        }
            break;
        case H_C:
        {
            height = var1;
            center = var2;
        }
            break;
        case C_NH:
        {
            center = var1;
            normalizedHeight = var2;
        }
            break;
        default:
            break;
    }
}

DVerticalLayout& DVerticalLayout::operator= (const DVerticalLayout& other)
{
    top = other.top;
    bottom = other.bottom;
    height = other.height;
    center = other.center;
    normalizedHeight = other.normalizedHeight;
    return *this;
}

bool DVerticalLayout::equals(const DVerticalLayout& target) const
{
    return (fabs(top - target.top) < F_ACCURACY)
        && (fabs(bottom - target.bottom) < F_ACCURACY)
        && (fabs(height - target.height) < F_ACCURACY)
        && (fabs(center - target.center) < F_ACCURACY)
        && (fabs(normalizedHeight - target.normalizedHeight) < F_ACCURACY);
}



DLayout::DLayout()
:horizontal(DHorizontalLayout())
,vertical(DVerticalLayout())
{

}

DLayout::DLayout(const DLayout& other)
:horizontal(other.horizontal)
,vertical(other.vertical)
{
    
}

DLayout::DLayout(const DHorizontalLayout& horizontal, const DVerticalLayout& vertical)
:horizontal(horizontal)
,vertical(vertical)
{
    
}

DLayout& DLayout::operator= (const DLayout& other)
{
    horizontal = other.horizontal;
    vertical = other.vertical;
    return *this;
}

bool DLayout::equals(const DLayout& target) const
{
    return horizontal.equals(target.horizontal)
        && vertical.equals(target.vertical);
}

NS_CC_END
