const findTime = (times) => {

    try {
        let startTime = [parseInt(times.split("-")[0].substring(0, 2)), parseInt(times.split("-")[0].substring(2))];
        let endTime = [parseInt(times.split("-")[1].substring(0, 2)), parseInt(times.split("-")[1].substring(2))];

        // (end_hours * 60 + end_minutes) - (start_hours * 60 + start_minutes)
        return (endTime[0] * 60 + endTime[1]) - (startTime[0] * 60 + startTime[1]);
    } catch (error) {
        return 0;
    }
}

const onTimesSubmit = (event) => {
    event.preventDefault();

    let sum = 0;
    let sundayTimes = findTime(document.getElementById("sunday_times").value);
    let mondayTimes = findTime(document.getElementById("monday_times").value);
    let tuesdayTimes = findTime(document.getElementById("tuesday_times").value);
    let wednesdayTimes = findTime(document.getElementById("wednesday_times").value);
    let thursdayTimes = findTime(document.getElementById("thursday_times").value);
    let fridayTimes = findTime(document.getElementById("friday_times").value);
    let saturdayTimes = findTime(document.getElementById("saturday_times").value);

    sum += sundayTimes;
    sum += mondayTimes;
    sum += tuesdayTimes;
    sum += wednesdayTimes;
    sum += thursdayTimes;
    sum += fridayTimes;
    sum += saturdayTimes;

    total_times.textContent = `${sundayTimes} + ${mondayTimes} + ${tuesdayTimes} + ${wednesdayTimes} + ${thursdayTimes} + ${fridayTimes} + ${saturdayTimes} = ${sum} minutes`;

    let hours = Math.floor(sum / 60);
    let minutes = sum % 60;

    hoursAndMinutes.textContent = `${hours} hours and ${minutes} minutes`;
}

const onWageSubmit = (event) => {
    event.preventDefault();

    try {
        let wage = parseFloat(document.getElementById("wage").value);
        let hoursWorked = parseInt(hoursAndMinutes.textContent.split(" ")[0])
        let minutesWorked = parseInt(hoursAndMinutes.textContent.split(" ")[3]);
        // console.log(wage);
        // console.log(hoursWorked);
        // console.log(minutesWorked);

        let total = wage * hoursWorked + wage * (minutesWorked / 60);
        total.equals(NaN) ? total_wage.textContent = `There was an error trying to calculate the total` : total_wage.textContent = `Your resulting amount is: $${total}`;
    } catch (error) {
        total_wage.textContent = `There was an error trying to calculate the total`;
    }
}

const timesForm = document.getElementById("times_form");
const total_times = document.getElementById("total_times");
const hoursAndMinutes = document.getElementById("hours_and_minutes");
timesForm.addEventListener("submit", onTimesSubmit);

const wageForm = document.getElementById("wage_form");
const total_wage = document.getElementById("total_wage");
wageForm.addEventListener("submit", onWageSubmit);