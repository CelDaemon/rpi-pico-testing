# Initialisation Tests
| Situation                     | Action               | Expected Outcome                     | Observed Outcome                    | Suceeded |
| ----------------------------- | -------------------- | ------------------------------------ | ----------------------------------- | -------- |
| The test setup is not powered | Power the test setup | The setup does not burst into flames | The setup did not burst into flames | X        |
| The test setup is not powered | Power the test setup | The leftmost LED turns on            | The leftmost LED turns on           | X        |

# LED Tests
| Situation               | Action                                                                        | Expected Outcome                             | Observed Outcome                               | Suceeded |
| ----------------------- | ----------------------------------------------------------------------------- | -------------------------------------------- | ---------------------------------------------- | -------- |
| The leftmost LED is on  | Press the rightmost lift button                                               | The leftmost LED turns off after ~2 seconds  | The leftmost LED turns off after 2 seconds  | X        |
| The leftmost LED is on  | Press the rightmost lift button                                               | The centre LED turns on after ~2 seconds     | The centre LED turns on after 2 seconds     | X        |
| The leftmost LED is on  | Press the rightmost lift button                                               | The centre LED turns off after ~4 seconds    | The centre LED turns off after 4 seconds    | X        |
| The leftmost LED is on  | Press the rightmost lift button                                               | The rightmost LED turns on after ~4 seconds  | The rightmost LED turns on after 4 seconds  | X        |
| The rightmost LED is on | Press the leftmost lift button                                                | The rightmost LED turns off after ~2 seconds | The rightmost LED turns off after 2 seconds | X        |
| The rightmost LED is on | Press the leftmost lift button                                                | The centre LED turns on after ~2 seconds     | The centre LED turns on after 2 seconds     | X        |
| The rightmost LED is on | Press the leftmost lift button                                                | The centre LED turns off after ~4 seconds    | The centre LED turns off after 4 seconds    | X        |
| The rightmost LED is on | Press the leftmost lift button                                                | The leftmost LED turns on after ~4 seconds   | The leftmost LED turns on after 4 seconds   | X        |
| The centre LED is on    | Press the leftmost lift button                                                | The centre LED turns off after ~2 seconds    | The centre LED turns off after 2 seconds    | X        |
| The centre LED is on    | Press the leftmost lift button                                                | The leftmost LED turns on after ~2 seconds   | The leftmost LED turns on after 2 seconds   | X        |
| The centre LED is on    | Press the rightmost lift button                                               | The centre LED turns off after ~2 seconds    | The centre LED turns off after 2 seconds    | X        |
| The centre LED is on    | Press the rightmost lift button                                               | The rightmost LED turns on after ~2 seconds  | The rightmost LED turns on after 2 seconds  | X        |
| The leftmost LED is on  | Press the centre lift button                                                  | The centre LED turns on after ~2 seconds     | The centre LED turns on after 2 seconds     | X        |
| The leftmost LED is on  | Press the centre lift button                                                  | The rightmost LED does not turn on           | The rightmost LED does not turn on          | X        |
| The rightmost LED is on | Press the centre lift button                                                  | The centre LED turns on after ~2 seconds     | The centre LED turns on after 2 seconds     | X        |
| The rightmost LED is on | Press the centre lift button                                                  | The leftmost LED does not turn on            | The leftmost LED does not turn on           | X        |
| The leftmost LED is on  | Press the leftmost lift button                                                | The leftmost LED stays on                    | The leftmost LED stays on                   | X        |
| The rightmost LED is on | Press the rightmost lift button                                               | The rightmost LED stays on                   | The rightmost LED stays on                  | X        |
| The centre LED is on    | Press the centre lift button                                                  | The centre LED stays on                      | The centre LED stays on                     | X        |
| The leftmost LED is on  | Press the rightmost lift button, then repeatedly press the centre lift button | The centre LED turns on after ~2 seconds     | The centre LED turns on after 2 seconds     | X        |
| The rightmost LED is on | Press the leftmost lift button, then repeatedly press the centre lift button  | The centre LED turns on after ~2 seconds     | The centre LED turns on after 2 seconds     | X        |


# Alarm Tests
| Situation                 | Action                                                       | Expected Outcome                 | Observed Outcome                 | Suceeded |
| ------------------------- | ------------------------------------------------------------ | -------------------------------- | -------------------------------- | -------- |
| The test setup is powered | Press the alarm button                                       | The buzzer makes a beeping sound | The buzzer makes a beeping sound | X        |
| The leftmost LED is on    | Press the rightmost lift button, then press the alarm button | The centre LED does not turn on  | The centre LED does not turn on  | X        |
| The buzzer is beeping     | Press the leftmost lift button                               | The buzzer turns off             | The buzzer turns off             | X        |
| The buzzer is beeping     | Press the centre lift button                                 | The buzzer turns off             | The buzzer turns off             | X        |
| The buzzer is beeping     | Press the rightmost lift button                              | The buzzer turns off             | The buzzer turns off             | X        |

