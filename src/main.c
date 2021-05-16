#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>
#include <assert.h>
#include <stdio.h>

VkInstance vulkanOrnegi = VK_NULL_HANDLE;

int main(int argc, char **argv)
{
#pragma region DESTEKLENEN TÜM UZANTILARIN LİSTESİNİ YAZDIR
    uint32_t uzantiSayisi = 0;
    vkEnumerateInstanceExtensionProperties(NULL, &uzantiSayisi, NULL);
    VkExtensionProperties *uzantiOzellikleri = malloc(uzantiSayisi * sizeof(VkExtensionProperties));
    vkEnumerateInstanceExtensionProperties(NULL, &uzantiSayisi, uzantiOzellikleri);

    printf("|--------------------------------------------------|\n");
    printf("|            DESTEKLENEN TÜM UZANTILAR             |\n");
    printf("|--------------------------------------------------|\n");
    printf("|extensionName                         |specVersion|\n");
    printf("|--------------------------------------------------|\n");
    for (int i = 0; i < uzantiSayisi; i++)
        printf("|%-38s|%-11d|\n", uzantiOzellikleri[i].extensionName, uzantiOzellikleri[i].specVersion);
    printf("|--------------------------------------------------|\n");
    return 0;

#pragma endregion

    const char *etkinKatmanIsimleri[] = {"VK_LAYER_LUNARG_standard_validation"};
    const char *etkinUzantiIsimleri[] = {"VK_EXT_debug_report"};

    VkApplicationInfo uygulamaBilgisi = {
        sType : VK_STRUCTURE_TYPE_APPLICATION_INFO,
        pApplicationName : "Nokta",
        applicationVersion : VK_MAKE_VERSION(1, 0, 0),
        pEngineName : "Nokta Engine",
        engineVersion : VK_MAKE_VERSION(1, 0, 0),
        apiVersion : VK_MAKE_VERSION(1, 0, 0),
    };

    VkInstanceCreateInfo vulkanOrnegiOlusturmaBilgisi = {
        sType : VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
        pApplicationInfo : &uygulamaBilgisi,
        enabledLayerCount : 1,
        ppEnabledLayerNames : etkinKatmanIsimleri,
        enabledExtensionCount : 1,
        ppEnabledExtensionNames : etkinUzantiIsimleri,
    };

    VkResult result = vkCreateInstance(&vulkanOrnegiOlusturmaBilgisi, NULL, &vulkanOrnegi);

    assert(result == VK_SUCCESS);

    vkDestroyInstance(vulkanOrnegi, NULL);
}
