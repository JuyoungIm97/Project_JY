// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
//#include "JY_Define.generated.h"

/**
 * 
*/
DECLARE_LOG_CATEGORY_EXTERN(JY_Log, Log, All);

#define JY_LOG(InFormat, ...) UE_LOG(JY_Log, Log, InFormat, ##__VA_ARGS__)

#define JY_CHECK(expr) check(expr)

// Object
#define JY_NewObject NewObject

#define JY_DeleteObject(Object) {			\
JY_CHECK(Object != nullptr);					   \
Object->ConditionalBeginDestroy();	 \
};
