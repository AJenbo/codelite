#include "phpcsfixeroptions.h"
#include "cl_standard_paths.h"

PhpcsfixerOptions::PhpcsfixerOptions()
    : clConfigItem("phplint")
    , m_lintOnFileLoad(false)
    , m_lintOnFileSave(false)
    , m_phpcsPhar("")
    , m_phpmdPhar("")
    , m_phpmdRules("")
{
}

PhpcsfixerOptions::~PhpcsfixerOptions()
{
}

void PhpcsfixerOptions::FromJSON(const JSONElement& json)
{
    json.namedObject().isNull();
    m_phpcsPhar = json.namedObject("phpcsPhar").toString(m_phpcsPhar);
    m_phpmdPhar = json.namedObject("phpmdPhar").toString(m_phpmdPhar);
    m_phpmdRules = json.namedObject("phpmdRules").toString(m_phpmdRules);
}

JSONElement PhpcsfixerOptions::ToJSON() const
{
    JSONElement element = JSONElement::createObject(GetName());
    element.addProperty("lintOnFileLoad", m_lintOnFileLoad);
    element.addProperty("lintOnFileSave", m_lintOnFileSave);
    element.addProperty("phpcsPhar", m_phpcsPhar);
    element.addProperty("phpmdPhar", m_phpmdPhar);
    element.addProperty("phpmdRules", m_phpmdRules);
    return element;
}

void PhpcsfixerOptions::stuff()
{
    JSONRoot root(cJSON_Object);
    JSONElement rules = root.toElement();
    if(m_PHPCSFixerPharRules & kPcfPHP56Migration) {
        rules.addProperty("@PHP56Migration", true);
    }
    if(m_PHPCSFixerPharRules & kPcfPHP70Migration) {
        rules.addProperty("@PHP70Migration", true);
        if(m_PHPCSFixerPharRules & kPcfAllowRisky) {
            rules.addProperty("@PHP70Migration:risky", true);
        }
    }
    if(m_PHPCSFixerPharRules & kPcfPHP71Migration) {
        rules.addProperty("@PHP71Migration", true);
        if(m_PHPCSFixerPharRules & kPcfAllowRisky) {
            rules.addProperty("@PHP71Migration:risky", true);
        }
    }
    if(m_PHPCSFixerPharRules & kPcfPSR1) {
        rules.addProperty("@PSR1", true);
    }
    if(m_PHPCSFixerPharRules & kPcfPSR2) {
        rules.addProperty("@PSR2", true);
    }
    if(m_PHPCSFixerPharRules & kPcfSymfony) {
        rules.addProperty("@Symfony", true);
        if(m_PHPCSFixerPharRules & kPcfAllowRisky) {
            rules.addProperty("@Symfony:risky", true);
        }
    }
    if(m_PHPCSFixerPharRules & (kPcfShortArray | kPcfLongArray)) {
        JSONElement array_syntax = JSONElement::createObject("array_syntax");
        array_syntax.addProperty("syntax", m_PHPCSFixerPharRules & kPcfShortArray ? "short" : "long");
        rules.addProperty("array_syntax", array_syntax);
    }
    if(m_PHPCSFixerPharRules &
       (kPcfAlignDoubleArrow | kPcfStripDoubleArrow | kPcfAlignEquals | kPcfStripEquals | kPcfIgnoreDoubleArrow)) {
        JSONElement binary_operator_spaces = JSONElement::createObject("binary_operator_spaces");
        if(m_PHPCSFixerPharRules & (kPcfAlignDoubleArrow | kPcfStripDoubleArrow | kPcfIgnoreDoubleArrow)) {
            binary_operator_spaces.addProperty("align_double_arrow", m_PHPCSFixerPharRules & kPcfIgnoreDoubleArrow ?
                                               cJSON_NULL :
                                               m_PHPCSFixerPharRules & kPcfAlignDoubleArrow ? true : false);
        }
        if(m_PHPCSFixerPharRules & (kPcfAlignEquals | kPcfStripEquals | kPcfIgnoreEquals)) {
            binary_operator_spaces.addProperty("align_equals", m_PHPCSFixerPharRules & kPcfIgnoreEquals ?
                                               cJSON_NULL :
                                               m_PHPCSFixerPharRules & kPcfAlignEquals ? true : false);
        }
        rules.addProperty("binary_operator_spaces", binary_operator_spaces);
    }
    if(m_PHPCSFixerPharRules & (kPcfConcatSpaceNone | kPcfConcatSpaceOne)) {
        JSONElement concat_space = JSONElement::createObject("concat_space");
        concat_space.addProperty("spacing", m_PHPCSFixerPharRules & kPcfConcatSpaceNone ? "none" : "one");
        rules.addProperty("concat_space", concat_space);
    }
    if(m_PHPCSFixerPharRules & (kPcfEmptyReturnStrip | kPcfEmptyReturnKeep)) {
        rules.addProperty("phpdoc_no_empty_return", m_PHPCSFixerPharRules & kPcfEmptyReturnStrip ? true : false);
    }

    if(m_PHPCSFixerPharRules & kPcfBlankLineAfterOpeningTag) {
        rules.addProperty("blank_line_after_opening_tag", true);
    }
    if(m_PHPCSFixerPharRules & kPcfBlankLineBeforeReturn) {
        rules.addProperty("blank_line_before_return", true);
    }

    rules.addProperty(, true);
}

PhpcsfixerOptions& PhpcsfixerOptions::Load()
{
    clConfig config("php-cs-fixer.conf");
    config.ReadItem(this);
    return *this;
}

PhpcsfixerOptions& PhpcsfixerOptions::Save()
{
    clConfig config("php-cs-fixer.conf");
    config.WriteItem(this);
    return *this;
}
