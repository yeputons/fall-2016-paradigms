void set_result(int new_result) {
  pthread_mutex_lock(&guard);
  if (!flag) {
    flag = true;
    result = new_result;
  }
  pthread_mutex_unlock(&guard);
}

int get_result(void) {
  pthread_mutex_lock(&guard);
  int x = -1;
  if (flag) {
    x = result;
    flag = false;
  }
  pthread_mutex_unlock(&guard);
  return x;
}
