/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.h

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

#ifndef _BQ25731_DRIVER_H    /* Guard against multiple inclusion */
#define _BQ25731_DRIVER_H


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

/* This section lists the other files that are included in this file.
 */

/* TODO:  Include other files here if needed. */


/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif


    /* ************************************************************************** */
    /* ************************************************************************** */
    /* Section: Constants                                                         */
    /* ************************************************************************** */
    /* ************************************************************************** */

    /*  A brief description of a section can be given directly below the section
        banner.
     */


    /* ************************************************************************** */
    /** Descriptive Constant Name

      @Summary
        Brief one-line summary of the constant.
    
      @Description
        Full description, explaining the purpose and usage of the constant.
        <p>
        Additional description in consecutive paragraphs separated by HTML 
        paragraph breaks, as necessary.
        <p>
        Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.
    
      @Remarks
        Any additional remarks
     */

#define BQ25731_ADDR 0x6B
#define BQ25731_ID  0x2F
#define BQ25731_CHRGOPT_0B  0x00
#define BQ25731_CHRGOPT_0A  0x01
#define BQ25731_CHRGCURR2  0x02
#define BQ25731_CHRGCURR1  0x03
#define BQ25731_STATUS1  0x21
#define BQ25731_STATUS2  0x20
#define BQ25731_CHRGOPT_3B  0x34
#define BQ25731_CHRGOPT_3A  0x35
#define BQ25731_IIN_HOST_H  0x0F
#define BQ25731_IIN_HOST_L  0x0E
#define BQ25731_CHRGOPT_4B  0x3D

    // *****************************************************************************
    // *****************************************************************************
    // Section: Data Types
    // *****************************************************************************
    // *****************************************************************************

    /*  A brief description of a section can be given directly below the section
        banner.
     */


    // *****************************************************************************

    /** Descriptive Data Type Name

      @Summary
        Brief one-line summary of the data type.
    
      @Description
        Full description, explaining the purpose and usage of the data type.
        <p>
        Additional description in consecutive paragraphs separated by HTML 
        paragraph breaks, as necessary.
        <p>
        Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.

      @Remarks
        Any additional remarks
        <p>
        Describe enumeration elements and structure and union members above each 
        element or member.
     */
    //    typedef struct _example_struct_t {
    //        /* Describe structure member. */
    //        int some_number;
    //
    //        /* Describe structure member. */
    //        bool some_flag;
    //
    //    } example_struct_t;


    // *****************************************************************************
    // *****************************************************************************
    // Section: Interface Functions
    // *****************************************************************************
    // *****************************************************************************

    /*  A brief description of a section can be given directly below the section
        banner.
     */

    // *****************************************************************************

    /**
          @Function
            int ExampleFunctionName ( int param1, int param2 ) 

          @Summary
            Brief one-line description of the function.

          @Description
            Full description, explaining the purpose and usage of the function.
            <p>
            Additional description in consecutive paragraphs separated by HTML 
            paragraph breaks, as necessary.
            <p>
            Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.

          @Precondition
            List and describe any required preconditions. If there are no preconditions,
            enter "None."

          @Parameters
            @param param1 Describe the first parameter to the function.
    
            @param param2 Describe the second parameter to the function.

          @Returns
            List (if feasible) and describe the return values of the function.
            <ul>
              <li>1   Indicates an error occurred
              <li>0   Indicates an error did not occur
            </ul>

          @Remarks
            Describe any special behavior not described above.
            <p>
            Any additional remarks.

          @Example
            @code
            if(ExampleFunctionName(1, 2) == 0)
            {
                return 3;
            }
     */

    void bq25731_write(unsigned char reg_address, unsigned char val);
    void bq25731_read(unsigned char reg_address, unsigned char *val);
    void bq25731_write_verify(unsigned char reg_address, unsigned char write_val, unsigned char *read_val);

    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _BQ25731_DRIVER_H */

/* *****************************************************************************
 End of File
 */
