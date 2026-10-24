import datetime as dt
class Solution:
    def countDaysTogether(self, arriveAlice: str, leaveAlice: str, arriveBob: str, leaveBob: str) -> int:
        days = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
        daysCumm = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

        for i in range(1,len(days)):
            daysCumm[i] = daysCumm[i-1] + daysCumm[i]
        # print(daysCumm)

        aliceA = daysCumm[int(arriveAlice[:2])-1] - (days[int(arriveAlice[:2])-1] - int(arriveAlice[-2:]))
        aliceL = daysCumm[int(leaveAlice[:2])-1] - (days[int(leaveAlice[:2])-1] - int(leaveAlice[-2:]))

        bobA = daysCumm[int(arriveBob[:2])-1] - (days[int(arriveBob[:2])-1] - int(arriveBob[-2:]))
        bobL = daysCumm[int(leaveBob[:2])-1] - (days[int(leaveBob[:2])-1] - int(leaveBob[-2:]))
        # print(aliceA, aliceL, bobA, bobL)
        cnt = 0

        for day in range(aliceA, aliceL+1):
            if day >= bobA and day <= bobL:
                cnt += 1
        return cnt



