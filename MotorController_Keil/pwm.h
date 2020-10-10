#ifndef PWM_H_
#define PWM_H_

void FTM0_init(void);
void FTM0_set_duty_cycle(unsigned int duty_cycle, unsigned int frequency, int dir);
void FTM3_init(void);
void FTM3_set_duty_cycle(unsigned int duty_cycle, unsigned int frequency);


#endif /* PWM_H_ */
