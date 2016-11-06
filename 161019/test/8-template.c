// bool flag;
// int result;
// pthread_mutex_t guard;
void set_result(int new_result) {
  if (flag) return;
  flag = true;
  result = new_result;
}

int get_result(void) {
  if (!flag) return -1;
  flag = false;
  return result;
}
