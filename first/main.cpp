// first.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
int main()
{
	short k, m;
	short x, y, z;
	cin >> k;
	cin >> m;
	cin >> x;
	cin >> y;
	cin >> z;
	__asm {	
		mov ax, [m]

		imul ax

		mov bx, [k]

		cmp bx, ax
		mov ax, [x]
		mov dx, [y]
		mov bx, [z]
		je l_equal; =
		jg l_above; >
		jl l_below; <

	l_equal:
		cmp dx, 0
		jl m_1; <
		jmp m_2
	m_1:
		neg dx
	m_2:
		sub ax, 1
		sub bx, 1
		jmp end_p

	l_above:
		cmp bx, 0
		jl m_3; <
		jmp m_4
	m_3:
		neg bx
	m_4:
		sub dx, 1
		sub ax, 1
		jmp end_p

	l_below:
		cmp ax, 0
		jl m_5; <
		jmp m_6
	m_5:
		neg ax
	m_6:
		sub dx, 1
		sub bx, 1

	end_p:
		mov [x], ax
		mov [y], dx
		mov [z], bx
	}
	
	cout << x << " " << y << " " << z << endl;

	return 0;
}
