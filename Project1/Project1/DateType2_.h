#pragma once
/*
//算术类型
bool    //
char					//字符						最小尺寸：8位
wchar_t			 //宽字符					最小尺寸：16位
char16_t			 //Unicode字符	   	最小尺寸：16位
char32_t			 //Unicode字符		 最小尺寸：32位
short				 //短整型					 最小尺寸：16位
int					 //整型						 最小尺寸：16位
long					 //长整型				     最小尺寸：32位
long long			//长整型				     最小尺寸：64位
float					//单精度浮点数		     最小尺寸：6位有效数字
double				//双精度浮点数			 最小尺寸：10位有效数字
long double    //扩展精度浮点数		  最小尺寸：10位有效数字

//带符号类型可以表示：正数。负数或0，无符号类型则仅能表示大于等于0的值。

//类型：int ，short，long和long long 都是带符号类型的， 通过在这些类型名前添加unsigned就可以得到无符号类型。 类型unsigned int 可以缩写为unsigned。

//字符型被分为了三种：char，signed char 和 unsigned char。

//8 比特大小的unsigned char 可以表示0~255区间内的值，如果我们赋了一个去区间以外的值，则实际的结果是该值对256取模后所得的余数。因此，把-1赋给8比特大小的unsigned char所得的结果是255.

//从数学角度解读：

//取模运算时,对于负数,应该加上被除数的整数倍,使结果大于或等于0之后,再进行运算.

//也就是：(-1)%256 = (-1+256)%256=255%256=255


*/


/*
换行符			   \n
纵向制表符	   \v
反斜线			   \\
回车符			   \r
横向制表符      \t
退格符            \b
问号		           \?
进纸符            \f
报警（响铃）符    \a
双引号                 \''
单引号                 \'
*/

/*
前缀：u                 unicode16字符

            U                 unicode32字符

            L                  宽字符

            u8               utf-8

后缀：u或U    表示该字面值为无符号类型

             l或L     表示该字面值的类型至少为long

             ll或LL   表示该字面值的类型至少为long long 

             f或F      表示该字面值为float类型

前后缀可以交叉结合使用：后缀UL时，表示无符号长整型

*/

//在数学中是一种逢16进1的进位制。一般用数字0到9和字母A到F（或a~f）表示，其中:A~F表示10~15，这些称作十六进制数字。

/*
//如果想声明一个变量而非定义它，就在变量名前添加关键字：extern，而且不要显示的初始化变量。

extern int i； //声明i， 而非定义i。
int j；            //声明并定义j。   定义是因为： 如果定义变量时，没有指定初始值，则变量被“默认初始化”

//！！！！ 变量能且只能被定义一次，但是可以被多次声明。
extern double pi = 3.1416;   //定义。    任何包含了显式初始化的声明即称为定义。 这样的行为，是抵消了extern的作用。 extern语句如果包含初始值就不再是声明了。而变成了定义。


*/


/*
//c++ 关键字  63个。
asm
do
if
return
typedef
auto
double
inline
short
typeid
bool
dynamic_cast
int
signed
typename
break
else
long
sizeof
union
case
enum
mutable
static
unsigned
catch
explicit
namespace
static_cast
using
char
export
new
struct
virtual
class
extern
operator
switch
void
const
false
private
template
volatile
const_cast
float
protected
this
wchar_t
continue
for
public
throw
while
default
friend
register
true
delete
goto
reinterpret_cast
try

*/

/*

//c++  操作符替代名，现在支持，但个人不建议使用。//https://bbs.csdn.net/topics/190086840

and
bitand 
compl
not_eq
or_eq
and_eq
bitor
not
or
xor

*/


/*
所谓的“右值引用”，主要用于内置类。 严格来说，当我们使用术语“引用”时，指的其实时“左值引用”。
*/


