Sub Test()
a = 0
b = 31.223
N_1 = 1000
N_2 = 2500
N_3 = 10000
Range("B4") = N_1
Range("B5") = N_2
Range("B6") = N_3
N1 a, b, N_1
N2 a, b, N_2
N3 a, b, N_3
End Sub

Sub N1(a, b, n)
sum1 = Left_Rect_O(a, b, n)
sum2 = Left_Rect_L(a, b, n)
sum3 = Trapeze_O(a, b, n)
sum4 = Trapeze_L(a, b, n)
Range("C4") = sum1 - sum2
Range("D4") = sum3 - sum4
End Sub

Sub N2(a, b, n)
sum1 = Left_Rect_O(a, b, n)
sum2 = Left_Rect_L(a, b, n)
sum3 = Trapeze_O(a, b, n)
sum4 = Trapeze_L(a, b, n)
Range("C5") = sum1 - sum2
Range("D5") = sum3 - sum4
End Sub

Sub N3(a, b, n)
sum1 = Left_Rect_O(a, b, n)
sum2 = Left_Rect_L(a, b, n)
sum3 = Trapeze_O(a, b, n)
sum4 = Trapeze_L(a, b, n)
Range("C6") = sum1 - sum2
Range("D6") = sum3 - sum4
End Sub

Function f1(x)
For y = 0 To 35
     if (((x-2)*(x-2) + (y+5)*(y+5) <= 30*30) AND (((x+5)*(x+5))/(20*20)+((y-3)*(y-3))/(33*33) <= 1)) then 
        f1 = y
    End If
Next
End Function

Function f2(x)
    f2 = -0.355 * x + 5.3188
End Function


Function Left_Rect_O(a, b, n)
    Dim h
    h = (b - a) / n
    Dim sum
    For i = 0 To n
    sum = sum + h * f1(a + i * h)
    Next
    Left_Rect_O = sum
End Function

Function Left_Rect_L(a, b, n)
    Dim h
    h = (b - a) / n
    Dim sum
    For i = 0 To n
    sum = sum + h * f2(a + i * h)
    Next
    Left_Rect_L = sum
End Function

Function Trapeze_O(a, b, n)
    h = (b - a) / n
    sum = f1(a) + f1(b)
    For i = 1 To n - 1
        sum = sum + 2 * f1(a + i * h)
    Next
    sum = sum * h / 2
    Trapeze_O = sum
End Function

Function Trapeze_L(a, b, n)
    h = (b - a) / n
    sum = f2(a) + f2(b)
    For i = 1 To n - 1
        sum = sum + 2 * f2(a + i * h)
    Next
    sum = sum * h / 2
    Trapeze_L = sum
End Function
