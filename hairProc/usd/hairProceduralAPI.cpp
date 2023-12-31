//
// Copyright 2016 Pixar
//
// Licensed under the Apache License, Version 2.0 (the "Apache License")
// with the following modification; you may not use this file except in
// compliance with the Apache License and the following modification to it:
// Section 6. Trademarks. is deleted and replaced with:
//
// 6. Trademarks. This License does not grant permission to use the trade
//    names, trademarks, service marks, or product names of the Licensor
//    and its affiliates, except as required to comply with Section 4(c) of
//    the License and to reproduce the content of the NOTICE file.
//
// You may obtain a copy of the Apache License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the Apache License with the above modification is
// distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied. See the Apache License for the specific
// language governing permissions and limitations under the Apache License.
//
#include "./hairProceduralAPI.h"
#include "pxr/usd/usd/schemaRegistry.h"
#include "pxr/usd/usd/typed.h"

#include "pxr/usd/sdf/types.h"
#include "pxr/usd/sdf/assetPath.h"

PXR_NAMESPACE_OPEN_SCOPE

// Register the schema with the TfType system.
TF_REGISTRY_FUNCTION(TfType)
{
    TfType::Define<HairProcHairProceduralAPI,
        TfType::Bases< UsdAPISchemaBase > >();
    
}

/* virtual */
HairProcHairProceduralAPI::~HairProcHairProceduralAPI()
{
}

/* static */
HairProcHairProceduralAPI
HairProcHairProceduralAPI::Get(const UsdStagePtr &stage, const SdfPath &path)
{
    if (!stage) {
        TF_CODING_ERROR("Invalid stage");
        return HairProcHairProceduralAPI();
    }
    return HairProcHairProceduralAPI(stage->GetPrimAtPath(path));
}


/* virtual */
UsdSchemaKind HairProcHairProceduralAPI::_GetSchemaKind() const
{
    return HairProcHairProceduralAPI::schemaKind;
}

/* static */
bool
HairProcHairProceduralAPI::CanApply(
    const UsdPrim &prim, std::string *whyNot)
{
    return prim.CanApplyAPI<HairProcHairProceduralAPI>(whyNot);
}

/* static */
HairProcHairProceduralAPI
HairProcHairProceduralAPI::Apply(const UsdPrim &prim)
{
    if (prim.ApplyAPI<HairProcHairProceduralAPI>()) {
        return HairProcHairProceduralAPI(prim);
    }
    return HairProcHairProceduralAPI();
}

/* static */
const TfType &
HairProcHairProceduralAPI::_GetStaticTfType()
{
    static TfType tfType = TfType::Find<HairProcHairProceduralAPI>();
    return tfType;
}

/* static */
bool 
HairProcHairProceduralAPI::_IsTypedSchema()
{
    static bool isTyped = _GetStaticTfType().IsA<UsdTyped>();
    return isTyped;
}

/* virtual */
const TfType &
HairProcHairProceduralAPI::_GetTfType() const
{
    return _GetStaticTfType();
}

UsdAttribute
HairProcHairProceduralAPI::GetPrimAttr() const
{
    return GetPrim().GetAttribute(HairProcTokens->hairProcPrim);
}

UsdAttribute
HairProcHairProceduralAPI::CreatePrimAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(HairProcTokens->hairProcPrim,
                       SdfValueTypeNames->IntArray,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
HairProcHairProceduralAPI::GetParamuvAttr() const
{
    return GetPrim().GetAttribute(HairProcTokens->hairProcParamuv);
}

UsdAttribute
HairProcHairProceduralAPI::CreateParamuvAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(HairProcTokens->hairProcParamuv,
                       SdfValueTypeNames->Float2Array,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdAttribute
HairProcHairProceduralAPI::GetRestAttr() const
{
    return GetPrim().GetAttribute(HairProcTokens->hairProcRest);
}

UsdAttribute
HairProcHairProceduralAPI::CreateRestAttr(VtValue const &defaultValue, bool writeSparsely) const
{
    return UsdSchemaBase::_CreateAttr(HairProcTokens->hairProcRest,
                       SdfValueTypeNames->Float3Array,
                       /* custom = */ false,
                       SdfVariabilityVarying,
                       defaultValue,
                       writeSparsely);
}

UsdRelationship
HairProcHairProceduralAPI::GetTargetRel() const
{
    return GetPrim().GetRelationship(HairProcTokens->hairProcTarget);
}

UsdRelationship
HairProcHairProceduralAPI::CreateTargetRel() const
{
    return GetPrim().CreateRelationship(HairProcTokens->hairProcTarget,
                       /* custom = */ false);
}

namespace {
static inline TfTokenVector
_ConcatenateAttributeNames(const TfTokenVector& left,const TfTokenVector& right)
{
    TfTokenVector result;
    result.reserve(left.size() + right.size());
    result.insert(result.end(), left.begin(), left.end());
    result.insert(result.end(), right.begin(), right.end());
    return result;
}
}

/*static*/
const TfTokenVector&
HairProcHairProceduralAPI::GetSchemaAttributeNames(bool includeInherited)
{
    static TfTokenVector localNames = {
        HairProcTokens->hairProcPrim,
        HairProcTokens->hairProcParamuv,
        HairProcTokens->hairProcRest,
    };
    static TfTokenVector allNames =
        _ConcatenateAttributeNames(
            UsdAPISchemaBase::GetSchemaAttributeNames(true),
            localNames);

    if (includeInherited)
        return allNames;
    else
        return localNames;
}

PXR_NAMESPACE_CLOSE_SCOPE

// ===================================================================== //
// Feel free to add custom code below this line. It will be preserved by
// the code generator.
//
// Just remember to wrap code in the appropriate delimiters:
// 'PXR_NAMESPACE_OPEN_SCOPE', 'PXR_NAMESPACE_CLOSE_SCOPE'.
// ===================================================================== //
// --(BEGIN CUSTOM CODE)--
