/***********************************************************
 * File generated by the HALCON-Compiler hcomp version 20.11
 * Usage: Interface to C++
 *
 * Software by: MVTec Software GmbH, www.mvtec.com
 ***********************************************************/


#ifndef HCPP_HDLMODEL
#define HCPP_HDLMODEL

namespace HalconCpp
{

// Represents an instance of a Deep Neural Network.
class LIntExport HDlModel : public HHandle
{

public:

  // Create an uninitialized instance
  HDlModel():HHandle() {}

  // Copy constructor
  HDlModel(const HDlModel& source) : HHandle(source) {}

  // Copy constructor
  HDlModel(const HHandle& handle);

  // Create HDlModel from handle, taking ownership
  explicit HDlModel(Hlong handle);

  bool operator==(const HHandle& obj) const
  {
    return HHandleBase::operator==(obj);
  }

  bool operator!=(const HHandle& obj) const
  {
    return HHandleBase::operator!=(obj);
  }

protected:

  // Verify matching semantic type ('dl_model')!
  virtual void AssertType(Hphandle handle) const;

public:

  // Deep copy of all data represented by this object instance
  HDlModel Clone() const;



/*****************************************************************************
 * Operator-based class constructors
 *****************************************************************************/

  // create_dl_model_detection: Create a deep learning network for object detection.
  explicit HDlModel(const HString& Backbone, Hlong NumClasses, const HDict& DLModelDetectionParam);

  // create_dl_model_detection: Create a deep learning network for object detection.
  explicit HDlModel(const char* Backbone, Hlong NumClasses, const HDict& DLModelDetectionParam);

#ifdef _WIN32
  // create_dl_model_detection: Create a deep learning network for object detection.
  explicit HDlModel(const wchar_t* Backbone, Hlong NumClasses, const HDict& DLModelDetectionParam);
#endif

  // read_dl_model: Read a deep learning model from a file.
  explicit HDlModel(const HString& FileName);

  // read_dl_model: Read a deep learning model from a file.
  explicit HDlModel(const char* FileName);

#ifdef _WIN32
  // read_dl_model: Read a deep learning model from a file.
  explicit HDlModel(const wchar_t* FileName);
#endif




  /***************************************************************************
   * Operators                                                               *
   ***************************************************************************/

  // Apply a deep-learning-based network on a set of images for inference.
  HDictArray ApplyDlModel(const HDictArray& DLSampleBatch, const HTuple& Outputs) const;

  // Clear a deep learning model.
  static void ClearDlModel(const HDlModelArray& DLModelHandle);

  // Clear a deep learning model.
  void ClearDlModel() const;

  // Create a deep learning network for object detection.
  void CreateDlModelDetection(const HString& Backbone, Hlong NumClasses, const HDict& DLModelDetectionParam);

  // Create a deep learning network for object detection.
  void CreateDlModelDetection(const char* Backbone, Hlong NumClasses, const HDict& DLModelDetectionParam);

#ifdef _WIN32
  // Create a deep learning network for object detection.
  void CreateDlModelDetection(const wchar_t* Backbone, Hlong NumClasses, const HDict& DLModelDetectionParam);
#endif

  // Deserialize a deep learning model.
  void DeserializeDlModel(const HSerializedItem& SerializedItemHandle);

  // Return the parameters of a deep learning model.
  HTuple GetDlModelParam(const HString& GenParamName) const;

  // Return the parameters of a deep learning model.
  HTuple GetDlModelParam(const char* GenParamName) const;

#ifdef _WIN32
  // Return the parameters of a deep learning model.
  HTuple GetDlModelParam(const wchar_t* GenParamName) const;
#endif

  // Read a deep learning model from a file.
  void ReadDlModel(const HString& FileName);

  // Read a deep learning model from a file.
  void ReadDlModel(const char* FileName);

#ifdef _WIN32
  // Read a deep learning model from a file.
  void ReadDlModel(const wchar_t* FileName);
#endif

  // Serialize a deep learning model.
  HSerializedItem SerializeDlModel() const;

  // Set the parameters of a deep learning model.
  void SetDlModelParam(const HString& GenParamName, const HTuple& GenParamValue) const;

  // Set the parameters of a deep learning model.
  void SetDlModelParam(const HString& GenParamName, double GenParamValue) const;

  // Set the parameters of a deep learning model.
  void SetDlModelParam(const char* GenParamName, double GenParamValue) const;

#ifdef _WIN32
  // Set the parameters of a deep learning model.
  void SetDlModelParam(const wchar_t* GenParamName, double GenParamValue) const;
#endif

  // Train a deep learning model.
  HDict TrainDlModelBatch(const HDictArray& DLSampleBatch) const;

  // Write a deep learning model in a file.
  void WriteDlModel(const HString& FileName) const;

  // Write a deep learning model in a file.
  void WriteDlModel(const char* FileName) const;

#ifdef _WIN32
  // Write a deep learning model in a file.
  void WriteDlModel(const wchar_t* FileName) const;
#endif

  // Infer the sample and generate a heatmap.
  HDictArray GenDlModelHeatmap(const HDictArray& DLSample, const HString& HeatmapMethod, const HTuple& TargetClasses, const HDict& GenParam) const;

  // Infer the sample and generate a heatmap.
  HDictArray GenDlModelHeatmap(const HDictArray& DLSample, const char* HeatmapMethod, const HTuple& TargetClasses, const HDict& GenParam) const;

#ifdef _WIN32
  // Infer the sample and generate a heatmap.
  HDictArray GenDlModelHeatmap(const HDictArray& DLSample, const wchar_t* HeatmapMethod, const HTuple& TargetClasses, const HDict& GenParam) const;
#endif

  // Train a deep learning model for anomaly detection.
  HDict TrainDlModelAnomalyDataset(const HDictArray& DLSamples, const HDict& DLTrainParam) const;

  // Calculate scores to prune a deep learning model.
  void AddDlPruningBatch(const HDlPrune& DLPruningHandle, const HDictArray& DLSampleBatch) const;

  // Create a pruning data handle.
  HDlPrune CreateDlPruning(const HString& Mode, const HDict& GenParam) const;

  // Create a pruning data handle.
  HDlPrune CreateDlPruning(const char* Mode, const HDict& GenParam) const;

#ifdef _WIN32
  // Create a pruning data handle.
  HDlPrune CreateDlPruning(const wchar_t* Mode, const HDict& GenParam) const;
#endif

  // Prune a deep learning model.
  HDlModel GenDlPrunedModel(const HDlPrune& DLPruningHandle) const;

};

// forward declarations and types for internal array implementation

template<class T> class HSmartPtr;
template<class T> class HHandleBaseArrayRef;

typedef HHandleBaseArrayRef<HDlModel> HDlModelArrayRef;
typedef HSmartPtr< HDlModelArrayRef > HDlModelArrayPtr;


// Represents multiple tool instances
class LIntExport HDlModelArray : public HHandleBaseArray
{

public:

  // Create empty array
  HDlModelArray();

  // Create array from native array of tool instances
  HDlModelArray(HDlModel* classes, Hlong length);

  // Copy constructor
  HDlModelArray(const HDlModelArray &tool_array);

  // Destructor
  virtual ~HDlModelArray();

  // Assignment operator
  HDlModelArray &operator=(const HDlModelArray &tool_array);

  // Clears array and all tool instances
  virtual void Clear();

  // Get array of native tool instances
  const HDlModel* Tools() const;

  // Get number of tools
  virtual Hlong Length() const;

  // Create tool array from tuple of handles
  virtual void SetFromTuple(const HTuple& handles);

  // Get tuple of handles for tool array
  virtual HTuple ConvertToTuple() const;

protected:

// Smart pointer to internal data container
   HDlModelArrayPtr *mArrayPtr;
};

}

#endif
