// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CourseShooter/CourseShooterGameModeBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCourseShooterGameModeBase() {}
// Cross Module References
	COURSESHOOTER_API UClass* Z_Construct_UClass_ACourseShooterGameModeBase_NoRegister();
	COURSESHOOTER_API UClass* Z_Construct_UClass_ACourseShooterGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_CourseShooter();
// End Cross Module References
	void ACourseShooterGameModeBase::StaticRegisterNativesACourseShooterGameModeBase()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ACourseShooterGameModeBase);
	UClass* Z_Construct_UClass_ACourseShooterGameModeBase_NoRegister()
	{
		return ACourseShooterGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_ACourseShooterGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ACourseShooterGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_CourseShooter,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACourseShooterGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "CourseShooterGameModeBase.h" },
		{ "ModuleRelativePath", "CourseShooterGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ACourseShooterGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACourseShooterGameModeBase>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ACourseShooterGameModeBase_Statics::ClassParams = {
		&ACourseShooterGameModeBase::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_ACourseShooterGameModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ACourseShooterGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ACourseShooterGameModeBase()
	{
		if (!Z_Registration_Info_UClass_ACourseShooterGameModeBase.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACourseShooterGameModeBase.OuterSingleton, Z_Construct_UClass_ACourseShooterGameModeBase_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ACourseShooterGameModeBase.OuterSingleton;
	}
	template<> COURSESHOOTER_API UClass* StaticClass<ACourseShooterGameModeBase>()
	{
		return ACourseShooterGameModeBase::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACourseShooterGameModeBase);
	struct Z_CompiledInDeferFile_FID_CourseShooter_Source_CourseShooter_CourseShooterGameModeBase_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CourseShooter_Source_CourseShooter_CourseShooterGameModeBase_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ACourseShooterGameModeBase, ACourseShooterGameModeBase::StaticClass, TEXT("ACourseShooterGameModeBase"), &Z_Registration_Info_UClass_ACourseShooterGameModeBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACourseShooterGameModeBase), 759622461U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CourseShooter_Source_CourseShooter_CourseShooterGameModeBase_h_2432749637(TEXT("/Script/CourseShooter"),
		Z_CompiledInDeferFile_FID_CourseShooter_Source_CourseShooter_CourseShooterGameModeBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CourseShooter_Source_CourseShooter_CourseShooterGameModeBase_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
