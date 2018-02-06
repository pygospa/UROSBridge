#pragma once
#include "ROSBridgeMsg.h"


class FROSBridgeMsgSensormsgsPointField : public FROSBridgeMsg
{

public:

	// Enum to encode the datatype of this point field
	enum EDataType : uint8
	{
		INT8 = 1,
		UINT8 = 2,
		INT16 = 3,
		UINT16 = 4,
		INT32 = 5,
		UINT32 = 6,
		FLOAT32 = 7,
		FLOAT64 = 8
	};

private:

	FString name;
	uint32 offset;
	EDataType datatype;
	uint32 count;

public:

    FROSBridgeMsgSensormsgsPointField()
    {
        MsgType = "sensor_msgs/PointField";
    }

    FROSBridgeMsgSensormsgsPointField
    (FString name_, uint32 offset_, EDataType datatype_, uint32 count_)
		:
        name(name_),
		offset(offset_),
		datatype(datatype_),
		count(count_)
    {
        MsgType = "sensor_msgs/PointField";
    }

    ~FROSBridgeMsgSensormsgsPointField() override {}

	static FString EDataTypeAsString(EDataType datatype)
	{
		switch (datatype)
		{
		case INT8:
			return TEXT("INT8");
			break;
		case UINT8:
			return TEXT("UINT8");
			break;
		case INT16:
			return TEXT("INT16");
			break;
		case UINT16:
			return TEXT("UINT16");
			break;
		case INT32:
			return TEXT("INT32");
			break;
		case UINT32:
			return TEXT("UINT32");
			break;
		case FLOAT32:
			return TEXT("FLOAT32");
			break;
		case FLOAT64:
			return TEXT("FLOAT64");
			break;
		default:
			return TEXT("Unknown");
		}
	}

	FString GetName() const	{ return name; }
	uint32 GetOffset() const { return offset; }
	EDataType GetDatatype() const {	return datatype; }
	uint32 GetCount() const { return count;	}

    void SetName(FString name_) { name = name_; }
	void SetOffset(uint32 offset_) { offset = offset_; }
	void SetDatatype(EDataType datatype_) {	datatype = datatype_; }
	void SetCount(uint32 count_) { count = count_; }

    virtual void FromJson(TSharedPtr<FJsonObject> JsonObject) override
	{
		name = JsonObject->GetStringField(TEXT("name"));
		offset = JsonObject->GetNumberField(TEXT("offset"));
		datatype = (EDataType) ((uint8)(JsonObject->GetNumberField(TEXT("datatype"))));
		count = JsonObject->GetNumberField(TEXT("count"));
    }

    static FROSBridgeMsgSensormsgsPointField GetFromJson(TSharedPtr<FJsonObject> JsonObject)
    {
        FROSBridgeMsgSensormsgsPointField Result;
        Result.FromJson(JsonObject);
        return Result;
    }

    virtual FString ToString() const override
    {
        return TEXT("PointField { name = ") + name +
			TEXT(", offset = ") + FString::FromInt(offset) +
			TEXT(", datatype = ") + EDataTypeAsString(datatype) +
			TEXT(", count = ") + FString::FromInt(count) +
			TEXT(" } ");
    }

    virtual TSharedPtr<FJsonObject> ToJsonObject() const override {
        TSharedPtr<FJsonObject> Object = MakeShareable<FJsonObject>(new FJsonObject());

        Object->SetStringField(TEXT("name"), name);
		Object->SetNumberField(TEXT("offset"), offset);
		Object->SetNumberField(TEXT("datatype"), datatype);
		Object->SetNumberField(TEXT("count"), count);

        return Object;
    }

    virtual FString ToYamlString() const override {
        FString OutputString;
        TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&OutputString);
        FJsonSerializer::Serialize(ToJsonObject().ToSharedRef(), Writer);
        return OutputString;
    }
};

/************************************************************************/
/* Namespace version                                                    */
/************************************************************************/
namespace sensor_msgs
{
	class PointField : public FROSBridgeMsg
	{

	public:

		// Enum to encode the datatype of this point field
		enum EDatatype : uint8
		{
			INT8 = 1,
			UINT8 = 2,
			INT16 = 3,
			UINT16 = 4,
			INT32 = 5,
			UINT32 = 6,
			FLOAT32 = 7,
			FLOAT64 = 8
		};

	private:

		FString Name;
		uint32 Offset;
		EDatatype Datatype;
		uint32 Count;

	public:

		PointField()
		{
			MsgType = "sensor_msgs/PointField";
		}

		PointField
		(FString InName, uint32 InOffset, EDatatype InDatatype, uint32 InCount)
			:
			Name(InName),
			Offset(InOffset),
			Datatype(InDatatype),
			Count(InCount)
		{
			MsgType = "sensor_msgs/PointField";
		}

		~PointField() override {}

		static FString EDataTypeAsString(EDatatype InDatatype)
		{
			switch (InDatatype)
			{
			case INT8:
				return TEXT("INT8");
				break;
			case UINT8:
				return TEXT("UINT8");
				break;
			case INT16:
				return TEXT("INT16");
				break;
			case UINT16:
				return TEXT("UINT16");
				break;
			case INT32:
				return TEXT("INT32");
				break;
			case UINT32:
				return TEXT("UINT32");
				break;
			case FLOAT32:
				return TEXT("FLOAT32");
				break;
			case FLOAT64:
				return TEXT("FLOAT64");
				break;
			default:
				return TEXT("Unknown");
			}
		}

		FString GetName() const 
		{
			return Name; 
		}

		uint32 GetOffset() const 
		{
			return Offset;
		}

		EDatatype GetDatatype() const 
		{ 
			return Datatype; 
		}

		uint32 GetCount() const 
		{ 
			return Count; 
		}

		void SetName(FString InName) 
		{ 
			Name = InName; 
		}

		void SetOffset(uint32 InOffset) 
		{ 
			Offset = InOffset;
		}

		void SetDatatype(EDatatype InDatatype) 
		{ 
			Datatype = InDatatype; 
		}

		void SetCount(uint32 InCount) 
		{
			Count = InCount;
		}

		virtual void FromJson(TSharedPtr<FJsonObject> JsonObject) override
		{
			Name = JsonObject->GetStringField(TEXT("name"));
			Offset = JsonObject->GetNumberField(TEXT("offset"));
			Datatype = (EDatatype)((uint8)(JsonObject->GetNumberField(TEXT("datatype"))));
			Count = JsonObject->GetNumberField(TEXT("count"));
		}

		static PointField GetFromJson(TSharedPtr<FJsonObject> JsonObject)
		{
			PointField Result;
			Result.FromJson(JsonObject);
			return Result;
		}

		virtual FString ToString() const override
		{
			return TEXT("PointField { name = ") + Name +
				TEXT(", offset = ") + FString::FromInt(Offset) +
				TEXT(", datatype = ") + EDataTypeAsString(Datatype) +
				TEXT(", count = ") + FString::FromInt(Count) +
				TEXT(" } ");
		}

		virtual TSharedPtr<FJsonObject> ToJsonObject() const override 
		{
			TSharedPtr<FJsonObject> Object = MakeShareable<FJsonObject>(new FJsonObject());

			Object->SetStringField(TEXT("name"), Name);
			Object->SetNumberField(TEXT("offset"), Offset);
			Object->SetNumberField(TEXT("datatype"), Datatype);
			Object->SetNumberField(TEXT("count"), Count);

			return Object;
		}

		virtual FString ToYamlString() const override 
		{
			FString OutputString;
			TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&OutputString);
			FJsonSerializer::Serialize(ToJsonObject().ToSharedRef(), Writer);
			return OutputString;
		}
	};
} // namespace sensor_msgs