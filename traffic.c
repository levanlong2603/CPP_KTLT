#include "main.h"

void SystemClock_Config(void);
static void MX_GPIO_Init(void);


//7 segment 1
#define A1 GPIO_PIN_0	//Port A
#define B1 GPIO_PIN_1
#define C1 GPIO_PIN_2
#define D1 GPIO_PIN_3
#define E1 GPIO_PIN_4
#define F1 GPIO_PIN_5
#define G1 GPIO_PIN_6
#define DIGIT11 GPIO_PIN_0	//Port B
#define DIGIT21 GPIO_PIN_1
//7 segment 2
#define A2 GPIO_PIN_10	//Port A
#define B2 GPIO_PIN_9
#define C2 GPIO_PIN_8
#define D2 GPIO_PIN_15	//Port B
#define E2 GPIO_PIN_14
#define F2 GPIO_PIN_13
#define G2 GPIO_PIN_12
#define DIGIT12 GPIO_PIN_10	//Port B
#define DIGIT22 GPIO_PIN_11
//Traffic 1
#define Red1 GPIO_PIN_3	//Port B
#define Yellow1 GPIO_PIN_4
#define Green1 GPIO_PIN_5
//Traffic 2
#define Red2 GPIO_PIN_15	//Port A
#define Yellow2 GPIO_PIN_12
#define Green2 GPIO_PIN_11

typedef enum {RED_1, YELLOW_1, GREEN_1} Traffic_1;
Traffic_1 currentState_1 = RED_1;
typedef enum {RED_2, YELLOW_2, GREEN_2} Traffic_2;
Traffic_2 currentState_2 = GREEN_2;

void Red_V(){
	HAL_GPIO_WritePin(GPIOB,Red1,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB,Green1,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB,Yellow1,GPIO_PIN_RESET);
}

void Yellow_V(){
	HAL_GPIO_WritePin(GPIOB,Red1,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB,Green1,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB,Yellow1,GPIO_PIN_SET);
}

void Green_V(){
	HAL_GPIO_WritePin(GPIOB,Red1,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB,Green1,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB,Yellow1,GPIO_PIN_RESET);
}

void Red_H(){
	HAL_GPIO_WritePin(GPIOA,Red2,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA,Green2,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA,Yellow2,GPIO_PIN_RESET);
}

void Yellow_H(){
	HAL_GPIO_WritePin(GPIOA,Red2,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA,Green2,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA,Yellow2,GPIO_PIN_SET);
}

void Green_H(){
	HAL_GPIO_WritePin(GPIOA,Red2,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA,Green2,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA,Yellow2,GPIO_PIN_RESET);
}
unsigned char led7Hex[]={0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
int idx1[]={A1, B1, C1, D1, E1, F1, G1};
int idx2[]={A2, B2, C2, D2, E2, F2, G2};

void LED7Write_V(short digit, unsigned char b){
	if(digit==1){
		HAL_GPIO_WritePin(GPIOB, DIGIT21, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, DIGIT11, GPIO_PIN_SET);
	}
	else if(digit==2){
		HAL_GPIO_WritePin(GPIOB, DIGIT11, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, DIGIT21, GPIO_PIN_SET);
	}
	for(int i=0;i<7;i++){
		if(((b>>i)&(0x01))==0) HAL_GPIO_WritePin(GPIOA, idx1[i], GPIO_PIN_RESET);
		else HAL_GPIO_WritePin(GPIOA, idx1[i], GPIO_PIN_SET);
	}
}

void LED7Write_H(short digit, unsigned char b){
	if(digit==1){
		HAL_GPIO_WritePin(GPIOB, DIGIT22, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, DIGIT12, GPIO_PIN_SET);
	}
	else if(digit==2){
		HAL_GPIO_WritePin(GPIOB, DIGIT12, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, DIGIT22, GPIO_PIN_SET);
	}
	for(int i=0;i<7;i++){
		if(((b>>i)&(0x01))==0){
			if(i<3){
				HAL_GPIO_WritePin(GPIOA, idx2[i], GPIO_PIN_RESET);
			}
			else{
				HAL_GPIO_WritePin(GPIOB, idx2[i], GPIO_PIN_RESET);
			}
		}
		else{
			if(i<3){
				HAL_GPIO_WritePin(GPIOA, idx2[i], GPIO_PIN_SET);
			}
			else{
				HAL_GPIO_WritePin(GPIOB, idx2[i], GPIO_PIN_SET);
			}
		}
	}
}

void Off_V(){
	for(int i=0;i<7;i++) HAL_GPIO_WritePin(GPIOA, idx1[i], GPIO_PIN_SET);
}

void Off_H(){
	for(int i=0;i<7;i++){
		if(i<3){
			HAL_GPIO_WritePin(GPIOA, idx2[i], GPIO_PIN_SET);
		}
		else{
			HAL_GPIO_WritePin(GPIOB, idx2[i], GPIO_PIN_SET);
		}
	}
}
int main(void)
{

 
  HAL_Init();
  SystemClock_Config();

  MX_GPIO_Init();
	int red_time=31000;
	int yellow_time=3000;
	int green_time=28000;
	
	uint32_t start_1 = HAL_GetTick();
	uint32_t start_2 = HAL_GetTick();
	uint32_t startScan = HAL_GetTick();
	uint32_t startLED_1 = HAL_GetTick();
	uint32_t startLED_2 = HAL_GetTick();
	
	int timeRemaining_V = (red_time-1000)/1000;
	int timeRemaining_H = (green_time-1000)/1000;
	uint8_t currentDigit = 1;
	Red_V();
	Green_H();
	uint8_t check_V=1, check_H=1;
	

  while (1)
  {
    
		uint32_t currentTick = HAL_GetTick();
		
		switch(currentState_1){
			case RED_1:
				if(currentTick - start_1 >= 1000){
					timeRemaining_V--;
					if(timeRemaining_V<0) timeRemaining_V = (green_time-1000)/1000;
					start_1=currentTick;
				}
				if(currentTick - startLED_1 >= red_time){
					Green_V();
					currentState_1=GREEN_1;
					startLED_1=currentTick;
				}
				break;
			case YELLOW_1:
				if(currentTick - start_1 >= yellow_time){
					check_V=1;
					timeRemaining_V = (red_time-1000)/1000;
					start_1=currentTick;
				}
				if(currentTick - startLED_1 >= yellow_time){
					Red_V();
					currentState_1=RED_1;
					startLED_1=currentTick;
				}
				break;
			case GREEN_1:
				if(currentTick - start_1 >= 1000){
					timeRemaining_V--;
					if(timeRemaining_V<0) check_V=0;
					start_1=currentTick;
				}
				if(currentTick - startLED_1 >= green_time){
					Yellow_V();
					currentState_1=YELLOW_1;
					startLED_1=currentTick;
				}
				break;
		}
		switch(currentState_2){
			case RED_2:
				if(currentTick - start_2 >= 1000){
					timeRemaining_H--;
					if(timeRemaining_H<0) timeRemaining_H = (green_time-1000)/1000;
					start_2=currentTick;
				}
				if(currentTick - startLED_2 >= red_time){
					Green_H();
					currentState_2=GREEN_2;
					startLED_2=currentTick;
				}
				break;
			case YELLOW_2:
				if(currentTick - start_2 >= yellow_time){
					check_H=1;
					timeRemaining_H = (red_time-1000)/1000;;
					start_2=currentTick;
				}
				if(currentTick - startLED_2 >= yellow_time){
					Red_H();
					currentState_2=RED_2;
					startLED_2=currentTick;
				}
				break;
			case GREEN_2:
				if(currentTick - start_2 >= 1000){
					timeRemaining_H--;
					if(timeRemaining_H<0) check_H=0;
					start_2=currentTick;
				}
				if(currentTick - startLED_2 >= green_time){
					Yellow_H();
					currentState_2=YELLOW_2;
					startLED_2=currentTick;
				}
				break;
		}
		
		if(currentTick - startScan >=5){
			short digit1_V = timeRemaining_V/10;
			short digit2_V = timeRemaining_V%10;
			short digit1_H = timeRemaining_H/10;
			short digit2_H = timeRemaining_H%10;
			if(currentDigit==1){
				if(check_V) LED7Write_V(1, led7Hex[digit1_V]);
				else Off_V();
				if(check_H) LED7Write_H(1, led7Hex[digit1_H]);
				else Off_H();
				currentDigit=2;
			}
			else{
				if(check_V) LED7Write_V(2, led7Hex[digit2_V]);
				else Off_V();
				if(check_H) LED7Write_H(2, led7Hex[digit2_H]);
				else Off_H();
				currentDigit=1;
			}
			startScan=currentTick;
		}
  }
}

void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

 
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}


static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4
                          |GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_8
                          |GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_15, GPIO_PIN_RESET);

  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_10
                          |GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);

  GPIO_InitStruct.Pin =  GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4
                          |GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8
                          |GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_10
                          |GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

void Error_Handler(void)
{
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT

void assert_failed(uint8_t *file, uint32_t line)
{
}
#endif /* USE_FULL_ASSERT */
