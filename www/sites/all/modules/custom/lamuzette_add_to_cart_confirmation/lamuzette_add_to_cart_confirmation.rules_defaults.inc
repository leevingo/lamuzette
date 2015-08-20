<?php

/**
 * @file
 * Default rule configurations for Commerce add to cart confirmation.
 */

/**
 * Implements hook_default_rules_configuration().
 */
function lamuzette_add_to_cart_confirmation_default_rules_configuration() {
  $items = array();
  $items['lamuzette_add_to_cart_confirmation_message'] = entity_import('rules_config', '{ "lamuzette_add_to_cart_confirmation_message" : {
      "LABEL" : "Add to Cart message",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "lamuzette_add_to_cart_confirmation", "commerce_cart" ],
      "ON" : [ "commerce_cart_product_add" ],
      "DO" : [ { "lamuzette_add_to_cart_confirmation_message" : [] } ]
    }
  }');
  return $items;
}

/**
 * Implements hook_default_rules_configuration_alter().
 */
function lamuzette_add_to_cart_confirmation_default_rules_configuration_alter(&$configs) {
  if (isset($configs['commerce_cart_add_to_cart_message'])) {
    // Disable the default add-to-cart message.
    $configs['commerce_cart_add_to_cart_message']->active = FALSE;
  }
}
