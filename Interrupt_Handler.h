#ifndef INTERRUPT_HANDLER_H
#define INTERRUPT_HANDLER_H

//Converts given parameter into a string during Compile-Time Only
#define To_String(s)	#s

/*------------------------------------------------------------------*/
/*------------------------Instructions------------------------------*/
#define sei()		__asm__ __volatile__ ("sei" ::)		//SEI Instruction
#define cli()		__asm__ __volatile__ ("cli" ::)		//CLI Instruction
#define reti()		__asm__ __volatile__ ("reti" ::)	//RETI Instruction

/*------------------------------------------------------------------*/
/*-------------------------Attributes-------------------------------*/
//Default Attribute, Disable Global interrupt
#define ISR_BLOCK

//Enable Global interrupt
#define ISR_NOBLOCK				__attribute__(interrupt)

//Basic asm used only, must place reti() at the end
#define ISR_NAKED				__attribute__(naked)

//Connect vector block to another vector block
#define ISR_ALIASOF(vector) 	__attribute__(alias(To_String(vector)))


/*------------------------------------------------------------------*/
/*-----------------------------ISR----------------------------------*/
#ifdef __cplusplus
	#define ISR(vector, ...)					\
		extern "C" void vector(void) __attribute__ ((signal, used)) __VA_ARGS__; \
		void vector (void)
#else
	#define ISR(vector, ...)				\
		void vector(void) __attribute__ ((signal, used)) __VA_ARGS__; \
		void vector (void)
#endif /* __cplusplus */


#endif /* INTERRUPT_HANDLER_H */
