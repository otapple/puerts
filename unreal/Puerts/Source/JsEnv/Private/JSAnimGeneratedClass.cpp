/*
 * Tencent is pleased to support the open source community by making Puerts available.
 * Copyright (C) 2020 THL A29 Limited, a Tencent company.  All rights reserved.
 * Puerts is licensed under the BSD 3-Clause License, except for the third-party components listed in the file 'LICENSE' which may
 * be subject to their corresponding license terms. This file is subject to the terms and conditions defined in file 'LICENSE',
 * which is part of this source code package.
 */

#include "JSAnimGeneratedClass.h"

#include "JSGeneratedFunction.h"

void UJSAnimGeneratedClass::StaticConstructor(const FObjectInitializer& ObjectInitializer)
{
    auto Class = static_cast<UJSAnimGeneratedClass*>(ObjectInitializer.GetClass());
    auto Object = ObjectInitializer.GetObj();
    Class->GetSuperClass()->ClassConstructor(ObjectInitializer);

    auto PinedDynamicInvoker = Class->DynamicInvoker.Pin();
    if (PinedDynamicInvoker)
    {
        PinedDynamicInvoker->JsConstruct(Class, Object, Class->Constructor, Class->Prototype);
    }
}

void UJSAnimGeneratedClass::InitPropertiesFromCustomList(uint8* DataPtr, const uint8* DefaultDataPtr)
{
    if (const FCustomPropertyListNode* CustomPropertyList = GetCustomPropertyListForPostConstruction())
    {
        UBlueprintGeneratedClass::InitPropertiesFromCustomList(CustomPropertyList, this, DataPtr, DefaultDataPtr);
    }
}

void UJSAnimGeneratedClass::Release()
{
    for (TFieldIterator<UFunction> It(this, EFieldIteratorFlags::IncludeSuper, EFieldIteratorFlags::ExcludeDeprecated,
             EFieldIteratorFlags::IncludeInterfaces);
         It; ++It)
    {
        if (auto Function = Cast<UJSGeneratedFunction>(*It))
        {
            // UE_LOG(LogTemp, Warning, TEXT("release: %s"), *Function->GetName());
            Function->JsFunction.Reset();
        }
    }

    Constructor.Reset();
    Prototype.Reset();
}
