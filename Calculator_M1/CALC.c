

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "CALC.h"


f32 Exp(f32 Copy_value)
{
    f32 tmp=1,ans=1;
    for(u8 i=1;i<100;i++)
    {
        tmp=tmp*Copy_value/i;
        ans+=tmp;
    }
    return ans;
}

f32 Ln(f32 Copy_value)
{
	f32 tmp=0;
	f32 x=11,y=11,ans=0;
	for(u8 i=0;i<100;i++)
    {
        ans=Exp(tmp)-Copy_value;

        if(ans==0)
             break;

        else if(ans<0)
           {
               y=tmp;
               tmp=(x+y)/2;
           }
        else
            {
                x=tmp;
                tmp=(x+y)/2;
            }
    }
	return tmp;
}

f32 Cos(f32 Copy_value)
{
	f32 y=Copy_value*22/(7*180);
	
	f32 ans=1,tmp=1;

    for(u8 i=1;i<=200;i+=2)
	{
		tmp=tmp*(-1)*y*y/((i+1)*i);

		ans+=tmp;
	}
	return ans;
}

f32 Sin(f32 Copy_value)
{
	f32 y=Copy_value*22/(7*180);
	f32 tmp=y,ans=y;
    for(u8 i=1;i<=200;i+=2)
	{
		tmp=tmp*(-1)*y*y/((i+1)*(i+2));

		ans+=tmp;
	}
	return ans;
}

f32 Tan(f32 Copy_value)
{
	return Sin(Copy_value)/Cos(Copy_value);
}
