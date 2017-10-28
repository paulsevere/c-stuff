struct record_s {
  unsigned long key;
  union value {
    char* s;
  };
};