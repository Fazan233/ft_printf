//
// Created by angryjoe on 29.12.18.
//

char write_digit_base(int n)
{
    if (n >= 0 && n <= 9)
        return ('0' + n);
    else
        return ('a' + (n - 10));
}