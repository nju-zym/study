#pragma once

#include <cmath>  // 引入 abs 所需头文件
#include <iostream>
using std::abs;
using std::cin;
using std::cout;

#ifndef DATE_H
#  define DATE_H

struct Year {
  explicit Year(int value) : value(value) {}
  int value;
};

struct Month {
  explicit Month(int value) : value(value) {}
  int value;
};

struct Day {
  explicit Day(int value) : value(value) {}
  int value;
};

class Date {
 private:
  int year;
  int month;
  int day;

 public:
  // 构造函数
  Date(int y, int m, int d);
  Date(Year y, Month m, Day d);

  // 判断日期是否合法
  bool isValidDate() const;

  // 判断是否是闰年
  bool isLeapYear(int y) const;

  // 返回该月的天数
  int daysInMonth(int m, int y) const;

  // 计算从某个日期到另一个日期的天数差（绝对值）
  int calculateDaysBetween(Date const& other) const;

  // 计算从公元1年1月1日到当前日期的天数
  int daysSinceEpoch() const;

  // 显示日期
  void display() const;
};

#endif

// 构造函数

Date::Date(Year y, Month m, Day d) : year(y.value), month(m.value), day(d.value) {
  if (!isValidDate()) {
    // 不需修改，我们希望看到某些异常日期测试用例对应的"-1"输出
  }
}

// 判断日期是否合法
bool Date::isValidDate() const {
  // TODO
  // 这个函数需要被其他函数使用
  // 未到日期也属于正常输入
  if (year < 1 || month < 1 || month > 12 || day < 1 || day > 31) {
    return false;
  }
  if (month == 2) {
    if (isLeapYear(year)) {
      if (day > 29) {
        return false;
      }
    } else {
      if (day > 28) {
        return false;
      }
    }
  }
  if (month == 4 || month == 6 || month == 9 || month == 11) {
    if (day > 30) {
      return false;
    }
  }
  return true;
}

// 判断是否是闰年
bool Date::isLeapYear(int y) const {
  // TODO
  if (y % 4 == 0 && y % 100 != 0) {
    return true;
  }
  if (y % 400 == 0) {
    return true;
  }
  return false;
}

// 返回该月的天数
int Date::daysInMonth(int m, int y) const {
  // TODO
  // 错误返回0
  if (m < 1 || m > 12) {
    return 0;
  }
  if (m == 2) {
    if (isLeapYear(y)) {
      return 29;
    } else {
      return 28;
    }
  }
  if (m == 4 || m == 6 || m == 9 || m == 11) {
    return 30;
  }
  return 31;
}

// 计算从公元1年1月1日到当前日期的天数
int Date::daysSinceEpoch() const {
  int totalDays = 0;
  if (!isValidDate()) {
    return -1;
  }
  // 计算当前年份中到当前日期的天数
  for (int i = 1; i < month; i++) {
    totalDays += daysInMonth(i, year);
  }
  totalDays += day;

  totalDays += (year - 1) * 365;

  for (int i = 1; i < year; i++) {
    if (isLeapYear(i)) {
      totalDays++;
    }
  }

  return totalDays;
  // 如果非法，返回-1
}

// 计算从某个日期到另一个日期的天数差（绝对值）
int Date::calculateDaysBetween(Date const& other) const {
  // 如果任意一个日期非法，返回-1
  if (!isValidDate() || !other.isValidDate()) {
    return -1;
  }
  int diff = other.daysSinceEpoch() - daysSinceEpoch();
  return abs(diff);
}

// 显示日期
void Date::display() const {
  // TODO：按照yyyy-mm-dd格式输出,加一个换行
  // 如：cout<<2025-02-17<<endl;
  // 如果非法，输出-1

  if (!isValidDate()) {
    cout << -1 << '\n';
    return;
  }
  if (year < 10) {
    cout << "000";
  } else if (year < 100) {
    cout << "00";
  } else if (year < 1000) {
    cout << "0";
  }
  cout << year << "-";
  if (month < 10) {
    cout << "0";
  }
  cout << month << "-";
  if (day < 10) {
    cout << "0";
  }
  cout << day << '\n';
}

int main() {
  int y1 = 0;
  int m1 = 0;
  int d1 = 0;
  int y2 = 0;
  int m2 = 0;
  int d2 = 0;
  // 输入第一个日期
  cin >> y1 >> m1 >> d1;
  // 输入第二个日期
  cin >> y2 >> m2 >> d2;
  // 创建两个 Date 对象
  Date date1(y1, m1, d1);
  Date date2(y2, m2, d2);
  // 显示两个日期
  date1.display();
  date2.display();
  // 计算并输出日期差
  int diff = date1.calculateDaysBetween(date2);
  cout << diff << '\n';
  return 0;
}
