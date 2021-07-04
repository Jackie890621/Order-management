# Order-management
c++
## Objective
Every order contains its **id** and the time information, **date** , within that the order can be finished. 

Build up a **Tree** according to the **date** of each order.
## Provided function
### Include 4 functions

```c++
void OrderMGMT::addOrder(unsigned date, unsigned id)
```
* Add one order to your order management system according to its **date** .

  * If the **date** of the new order is the same as the **date** of the order already in your system, you **cannot** take the order.

```c++
void OrderMGMT::deleteOrders(unsigned start, unsigned end)
```
* Delete orders whose **date** is within the time interval defined from **start** to **end** .

  * The time interval is a closed interval.

```c++
list<unsigned> OrderMGMT::searchByDate(unsigned start, unsigned end)
```
* Search your tree to find the orders whose **date** is within the time interval defined from **start** to **end**. 
* Store their **id** in a list.
  * The time interval is a closed interval.
  * The **id** in the list are sorted according to their **date** (earliest first).

```c++
list<unsigned> OrderMGMT::searchByDateRank(unsigned a_th, unsigned b_th)
```
* Search your tree to find a sequence of orders starting from the **a_th** rank of date and ending with the **b_th** rank of **date**. 
* Store their **id** in a list.
  * The **id** in the list are sorted according to the rank of their **date** (earliest first).
  * The order with the earliest **date** ranks 1st.
  * If **b_th** is larger than the number of the total orders, store the order sequence from the **a_th** rank of **date** to the number of the total orders.
  * If **a_th** is larger than the number of the total orders, store nothing.
## Testcase

![203004491_462715238515108_771708237732619493_n](https://user-images.githubusercontent.com/66109376/124377055-9b383500-dcdc-11eb-9de4-d58f90b3a7fd.png)

![204006607_2979474722333284_4911784595169497511_n](https://user-images.githubusercontent.com/66109376/124377062-a3907000-dcdc-11eb-842b-3ff3ea408bea.png)

![205339204_812223796094773_7703256808523376637_n](https://user-images.githubusercontent.com/66109376/124377067-aa1ee780-dcdc-11eb-8e57-1fbd20eead34.png)
## Platform
You may develop your software on UNIX/Linux.

Compile: $ g++ main.cpp -o hw4

Execution: $ ./hw4 "input file"
## Result

![203589307_173066851468701_1755610862496837973_n](https://user-images.githubusercontent.com/66109376/124377147-08e46100-dcdd-11eb-9b7c-8638f60fc99e.png)


