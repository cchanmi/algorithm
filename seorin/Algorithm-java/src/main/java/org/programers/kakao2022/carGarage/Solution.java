package org.programers.kakao2022.carGarage;

import java.util.*;

class Solution {

	int basicTime;
	int basicFee;
	int unitTime;
	int unitFee;

	public int[] solution(
			int[] fees,
			String[] records
	) {
		basicTime = fees[0];
		basicFee = fees[1];
		unitTime = fees[2];
		unitFee = fees[3];
		Map<String, Car> carMap = new HashMap<>();
		for (String record : records) {
			int time = Integer.parseInt(record.substring(0, 2)) * 60
					+ Integer.parseInt(record.substring(3, 5));
			String carNum = record.substring(6, 10);
			if (record.contains("IN")) {
				Car car = carMap.get(carNum);
				if (Objects.isNull(car)) {
					carMap.put(carNum, new Car(time));
				} else {
					car.setInTime(time);
				}
			} else {
				Car car = carMap.get(carNum);
				car.setOutTime(time);
			}
		}
		Map<String, Car> sortedMap = new TreeMap<>(carMap);
		List<Integer> answer = new ArrayList<>();
		for (String key : sortedMap.keySet()) {
			Car car = carMap.get(key);
			if (car.outTime == null) {
				car.setOutTime(23 * 60 + 59);
			}
			car.calFee();
			answer.add(car.totalFee);
		}
		return answer.stream().mapToInt(i -> i).toArray();
	}

	class Car {

		Integer inTime;
		Integer outTime;
		Integer stayTime;
		Integer totalFee;

		public Car(int inTime) {
			this.inTime = inTime;
			this.outTime = null;
			this.stayTime = 0;
			this.totalFee = 0;
		}

		public void setInTime(Integer inTime) {
			this.inTime = inTime;
			this.outTime = null;
		}

		public void setOutTime(int outTime) {
			this.outTime = outTime;
			this.stayTime += outTime - inTime;
		}

		public void calFee() {
			if (stayTime >= basicTime) {
				stayTime -= basicTime;
				totalFee += basicFee;
			} else {
				stayTime = 0;
				totalFee = basicFee;
			}
			totalFee += (stayTime % unitTime == 0) ?
					stayTime / unitTime * unitFee :
					(stayTime / unitTime + 1) * unitFee;
		}
	}
}