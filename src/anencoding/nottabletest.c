#include <iostream>
#include <limits.h>
#include <cstdlib>
#include <gmpxx.h>

const unsigned int A = 65535;

unsigned short tableUpper[65536];
unsigned short tableLower[65536];

void initNot(unsigned int x) {
  unsigned int notX = x;
  notX /= A;
  notX = ~notX;
  notX *= A;
  if (tableUpper[x / 0x10000] != 0 && tableUpper[x / 0x10000] != notX / 0x10000) {
    std::cout << "error:" << std::endl;
    std::cout << "x: " << x << std::endl;
    std::cout << "x/" << A << ": " << x / A << std::endl;
    std::cout << "notX: " << notX << std::endl;
    std::cout << "xNot / 0x10000: " << notX / 0x10000 << std::endl;
    std::cout << "xNot % 0x10000: " << notX % 0x10000 << std::endl;
    std::cout << "tableLower[" << x % 0x10000 << "]: " << tableLower[x % 0x10000] << std::endl;
    std::cout << "tableUpper[" << x / 0x10000 << "]: " << tableUpper[x / 0x10000] << std::endl;
    unsigned int x_table = tableUpper[x / 0x10000] * 0x10000 + tableLower[x % 0x10000];
    std::cout << "x_table = tableUpper[" << x / 0x10000
              << "] * 0x10000 + tableLower["  << x % 0x10000 << "]: "
              << x_table
              << std::endl;
    std::cout << "x_table / " << A << ": " << x_table / A << std::endl;
    std::cout << "~(x_table / " << A << "): " << ~(x_table / A) << std::endl;
    exit(-1);

  } else {
    unsigned int tbl = notX / 0x10000;
    tableUpper[x / 0x10000] = tbl;
  }
  if (tableLower[x % 0x10000] != 0 && tableLower[x % 0x10000] != notX % 0x10000) {
    std::cout << "error:" << std::endl;
    std::cout << "x: " << x << std::endl;
    std::cout << "x/" << A << ": " << x / A << std::endl;
    std::cout << "notX: " << notX << std::endl;
    std::cout << "xNot / 0x10000: " << notX / 0x10000 << std::endl;
    std::cout << "xNot % 0x10000: " << notX % 0x10000 << std::endl;
    std::cout << "tableLower[" << x % 0x10000 << "]: " << tableLower[x % 0x10000] << std::endl;
    std::cout << "tableUpper[" << x / 0x10000 << "]: " << tableUpper[x / 0x10000] << std::endl;
    unsigned int x_table = tableUpper[x / 0x10000] * 0x10000 + tableLower[x % 0x10000];
    std::cout << "x_table = tableUpper[" << x / 0x10000
              << "] * 0x10000 + tableLower["  << x % 0x10000 << "]: "
              << x_table
              << std::endl;
    std::cout << "x_table / " << A << ": " << x_table / A << std::endl;
    std::cout << "~(x_table / " << A << "): " << ~(x_table / A) << std::endl;
    exit(-1);
  } else {
    unsigned int tbl = notX % 0x10000;
    tableLower[x % 0x10000] = tbl;
  }
}

void reconstruct(unsigned int x) {
  unsigned int notX = x;
  notX /= A;
  notX = ~notX;
  notX *= A;
  unsigned int notX_table = tableUpper[x / 0x10000];
  notX_table *= 0x10000;
  notX_table += tableLower[x % 0x10000];
  unsigned int notX_table_lower = tableLower[x / 0x10000];
  notX_table_lower *= 0x10000;
  notX_table_lower += tableLower[x % 0x10000];
  unsigned int notX_table_upper = tableUpper[x / 0x10000];
  notX_table_upper *= 0x10000;
  notX_table_upper += tableUpper[x % 0x10000];
  if (notX != notX_table || notX != notX_table_lower || notX != notX_table_upper) {
    std::cout << "error:" << std::endl;
    std::cout << "x: " << x << std::endl;
    std::cout << "x/" << A << ": " << x / A << std::endl;
    std::cout << "notX: " << notX << std::endl;
    std::cout << "xNot / 0x10000: " << notX / 0x10000 << std::endl;
    std::cout << "xNot % 0x10000: " << notX % 0x10000 << std::endl;
    std::cout << "tableLower[" << x % 0x10000 << "]: " << tableLower[x % 0x10000] << std::endl;
    std::cout << "tableLower[" << x / 0x10000 << "]: " << tableLower[x / 0x10000] << std::endl;
    std::cout << "tableUpper[" << x % 0x10000 << "]: " << tableUpper[x % 0x10000] << std::endl;
    std::cout << "tableUpper[" << x / 0x10000 << "]: " << tableUpper[x / 0x10000] << std::endl;
    std::cout << "notX_table = tableUpper[" << x / 0x10000
              << "] * 0x10000 + tableLower["  << x % 0x10000 << "]: "
              << notX_table
              << std::endl;
    std::cout << "notX_table_lower = tableLower[" << x / 0x10000
              << "] * 0x10000 + tableLower["  << x % 0x10000 << "]: "
              << notX_table_lower
              << std::endl;
    std::cout << "notX_table_upper = tableUpper[" << x / 0x10000
              << "] * 0x10000 + tableUpper["  << x % 0x10000 << "]: "
              << notX_table_upper
              << std::endl;
    std::cout << "notX_table / " << A << ": " << notX_table / A << std::endl;
    std::cout << "~(notX_table / " << A << "): " << ~(notX_table / A) << std::endl;
    std::cout << "notX_table_lower / " << A << ": " << notX_table_lower / A << std::endl;
    std::cout << "~(notX_table_lower / " << A << "): " << ~(notX_table_lower / A) << std::endl;
    std::cout << "notX_table_upper / " << A << ": " << notX_table / A << std::endl;
    std::cout << "~(notX_table_upper / " << A << "): " << ~(notX_table_upper / A) << std::endl;
    exit(-1);
  }
}

int main(int argc, char *argv[]) {
  for (unsigned int i = 0; i < 65536; ++i) {
    tableUpper[i] = 0;
    tableLower[i] = 0;
  }
  for (unsigned int i = 0; i < INT_MAX; ++i) {
    initNot(i*A);
    if (i % (INT_MAX / 10) == 0) std::cout << 10 * (i / (INT_MAX / 10)) << std::endl;
  }
  for (unsigned int i = 1; i < INT_MAX; ++i) {
    reconstruct(i*A);
    if (i % (INT_MAX / 10) == 0) std::cout << 10 * (i / (INT_MAX / 10)) << std::endl;
  }
  return 0;
}








