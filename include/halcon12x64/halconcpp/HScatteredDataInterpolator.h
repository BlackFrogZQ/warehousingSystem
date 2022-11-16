/***********************************************************
 * File generated by the HALCON-Compiler hcomp version 20.11
 * Usage: Interface to C++
 *
 * Software by: MVTec Software GmbH, www.mvtec.com
 ***********************************************************/


#ifndef HCPP_HSCATTEREDDATAINTERPOLATOR
#define HCPP_HSCATTEREDDATAINTERPOLATOR

namespace HalconCpp
{

// Represents an instance of a scattered data interpolator.
class LIntExport HScatteredDataInterpolator : public HHandle
{

public:

  // Create an uninitialized instance
  HScatteredDataInterpolator():HHandle() {}

  // Copy constructor
  HScatteredDataInterpolator(const HScatteredDataInterpolator& source) : HHandle(source) {}

  // Copy constructor
  HScatteredDataInterpolator(const HHandle& handle);

  // Create HScatteredDataInterpolator from handle, taking ownership
  explicit HScatteredDataInterpolator(Hlong handle);

  bool operator==(const HHandle& obj) const
  {
    return HHandleBase::operator==(obj);
  }

  bool operator!=(const HHandle& obj) const
  {
    return HHandleBase::operator!=(obj);
  }

protected:

  // Verify matching semantic type ('scattered_data_interpolator')!
  virtual void AssertType(Hphandle handle) const;

public:



/*****************************************************************************
 * Operator-based class constructors
 *****************************************************************************/

  // create_scattered_data_interpolator: Creates an interpolator for the interpolation of scattered data.
  explicit HScatteredDataInterpolator(const HString& Method, const HTuple& Rows, const HTuple& Columns, const HTuple& Values, const HTuple& GenParamName, const HTuple& GenParamValue);

  // create_scattered_data_interpolator: Creates an interpolator for the interpolation of scattered data.
  explicit HScatteredDataInterpolator(const char* Method, const HTuple& Rows, const HTuple& Columns, const HTuple& Values, const HTuple& GenParamName, const HTuple& GenParamValue);

#ifdef _WIN32
  // create_scattered_data_interpolator: Creates an interpolator for the interpolation of scattered data.
  explicit HScatteredDataInterpolator(const wchar_t* Method, const HTuple& Rows, const HTuple& Columns, const HTuple& Values, const HTuple& GenParamName, const HTuple& GenParamValue);
#endif




  /***************************************************************************
   * Operators                                                               *
   ***************************************************************************/

  // Clear a scattered data interpolator.
  static void ClearScatteredDataInterpolator(const HScatteredDataInterpolatorArray& ScatteredDataInterpolatorHandle);

  // Clear a scattered data interpolator.
  void ClearScatteredDataInterpolator() const;

  // Interpolation of scattered data using a scattered data interpolator.
  HTuple InterpolateScatteredData(const HTuple& Row, const HTuple& Column) const;

  // Interpolation of scattered data using a scattered data interpolator.
  double InterpolateScatteredData(double Row, double Column) const;

  // Creates an interpolator for the interpolation of scattered data.
  void CreateScatteredDataInterpolator(const HString& Method, const HTuple& Rows, const HTuple& Columns, const HTuple& Values, const HTuple& GenParamName, const HTuple& GenParamValue);

  // Creates an interpolator for the interpolation of scattered data.
  void CreateScatteredDataInterpolator(const char* Method, const HTuple& Rows, const HTuple& Columns, const HTuple& Values, const HTuple& GenParamName, const HTuple& GenParamValue);

#ifdef _WIN32
  // Creates an interpolator for the interpolation of scattered data.
  void CreateScatteredDataInterpolator(const wchar_t* Method, const HTuple& Rows, const HTuple& Columns, const HTuple& Values, const HTuple& GenParamName, const HTuple& GenParamValue);
#endif

};

// forward declarations and types for internal array implementation

template<class T> class HSmartPtr;
template<class T> class HHandleBaseArrayRef;

typedef HHandleBaseArrayRef<HScatteredDataInterpolator> HScatteredDataInterpolatorArrayRef;
typedef HSmartPtr< HScatteredDataInterpolatorArrayRef > HScatteredDataInterpolatorArrayPtr;


// Represents multiple tool instances
class LIntExport HScatteredDataInterpolatorArray : public HHandleBaseArray
{

public:

  // Create empty array
  HScatteredDataInterpolatorArray();

  // Create array from native array of tool instances
  HScatteredDataInterpolatorArray(HScatteredDataInterpolator* classes, Hlong length);

  // Copy constructor
  HScatteredDataInterpolatorArray(const HScatteredDataInterpolatorArray &tool_array);

  // Destructor
  virtual ~HScatteredDataInterpolatorArray();

  // Assignment operator
  HScatteredDataInterpolatorArray &operator=(const HScatteredDataInterpolatorArray &tool_array);

  // Clears array and all tool instances
  virtual void Clear();

  // Get array of native tool instances
  const HScatteredDataInterpolator* Tools() const;

  // Get number of tools
  virtual Hlong Length() const;

  // Create tool array from tuple of handles
  virtual void SetFromTuple(const HTuple& handles);

  // Get tuple of handles for tool array
  virtual HTuple ConvertToTuple() const;

protected:

// Smart pointer to internal data container
   HScatteredDataInterpolatorArrayPtr *mArrayPtr;
};

}

#endif