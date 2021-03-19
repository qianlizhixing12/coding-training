class ParkingSystem {
private:
  int cap[4] = {0};
  int use[4] = {0};

public:
  ParkingSystem(int big, int medium, int small) {
    cap[1] = big;
    cap[2] = medium;
    cap[3] = small;
  }

  bool addCar(int carType) {
    if (use[carType] >= cap[carType]) {
      return false;
    }
    use[carType]++;
    return true;
  }
};