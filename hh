def get_desc_trans(request):

    optiondesc = [OptionDescriptionTrans.objects.filter(desc_id__id='2081').order_by('locales').values('option_desc')]

    optiondesc =  [y['option_feature'] for x in optiondesc for y in x]
    print('optiondesc:',optiondesc)

    locales = [OptionDescriptionTrans.objects.filter(desc_id__id='2081').order_by('locales').values('locales')]
    locales = [y['locales'] for x in locales for y in x]
    """b = OptionFeatureTrans.objects.filter((feature_id__in=queryset) & Q(locales=locale)).values(
        'feature_id__option_feature',
        'option_feature')

    data = [{blog['feature_id__option_feature']: blog['option_feature']} for blog in b]
    for i in data:
        for key, value in i.items():"""
    res={}
    for key in locales:
        for value in optiondesc:
            res[key]=value
            optiondesc.remove(value)
            break

    data={

        'data':res
    }
    return JsonResponse(data, safe=False)
